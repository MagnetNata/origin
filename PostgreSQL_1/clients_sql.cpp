#include "clients_sql.h"

DataBase::DataBase(const std::string& connection) : connection_{ connection } { std::cout << "Connected to database successfully!" << std::endl; };

void DataBase::createTables() 
{
    try
    {
        pqxx::work transaction_base(connection_);
        transaction_base.exec(R"(CREATE TABLE IF NOT EXISTS clients(id SERIAL PRIMARY KEY, name TEXT, surname TEXT, email TEXT UNIQUE);  
            CREATE TABLE IF NOT EXISTS phones(id SERIAL PRIMARY KEY, client_id INT REFERENCES clients(id), phone TEXT UNIQUE);)");
        transaction_base.commit();
        std::cout << "A database structure (tables) created" << std::endl;
    }
    catch (const std::exception& ex)
    {
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
        std::cerr << "Exception: " << ex.what() << std::endl;
    }
}

void DataBase::addNewClient(const std::string& name, const std::string& surname, const std::string& email, const std::string& phone) 
{

    try
    {
        pqxx::work transaction_base(connection_);
        connection_.set_client_encoding("UTF8");
        pqxx::result res = transaction_base.exec_params("INSERT INTO clients (name, surname, email) VALUES ($1, $2, $3) RETURNING id", name, surname, email);
        if (!res.empty())
        {
            int client_id = res[0][0].as<int>();
            transaction_base.exec_params("INSERT INTO phones (client_id, phone) VALUES ($1, $2);", client_id, phone);
            transaction_base.commit();
            std::cout << "Client added" << std::endl;
        }
        else
        {
            transaction_base.abort();
            std::cerr << "Failed to add client" << std::endl;
        }
    }
    catch (const std::exception& ex)
    {
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
        std::cerr << "Exception: " << ex.what() << std::endl;
    }
}

void DataBase::addPhone(const std::string& name, const std::string& phone) 
{
    pqxx::work transaction_base(connection_);
    pqxx::result res = transaction_base.exec_params("SELECT id, surname FROM clients WHERE name = $1", name);
    if (!res.empty())
    {
        int client_id = res[0][0].as<int>();
        transaction_base.exec_params("INSERT INTO phones (client_id, phone) VALUES ($1, $2)", client_id, phone);

        std::string client_surname = res[0][1].as<std::string>();
        transaction_base.commit();
        std::cout << "Phone added for client: " << client_id << " " << name << " " << client_surname << std::endl;
    }
    else
    {
        transaction_base.abort();
        std::cerr << "Client not found: " << name << std::endl;
    }
}

void DataBase::updateClient(const std::string& email, const std::string& newName, const std::string& newSurname, const std::string& newEmail) 
{
    pqxx::work transaction_base(connection_);
    pqxx::result res = transaction_base.exec_params("SELECT id FROM clients WHERE email = $1", email);
    if (!res.empty())
    {
        int client_id = res[0][0].as<int>();
        transaction_base.exec_params(R"(UPDATE clients SET name = $1, surname = $2, email = $3 WHERE id = $4)", newName, newSurname, newEmail, client_id);
        transaction_base.commit();
        std::cout << "Client updated: " << client_id << " " << newName << " " << newSurname << newEmail << std::endl;
    }
    else
    {
        transaction_base.abort();
        std::cerr << "Client not found: " << newName << std::endl;
    }
}

void DataBase::removePhone(const std::string& email, const std::string& phone) 
{
    pqxx::work transaction_base(connection_);
    pqxx::result res = transaction_base.exec_params("SELECT id, name, surname FROM clients WHERE email = $1", email);
    if (!res.empty())
    {
        int client_id = res[0][0].as<int>();
        transaction_base.exec_params("DELETE FROM phones WHERE client_id = $1 AND phone = $2", client_id, phone);
        transaction_base.commit();
        std::string client_name = res[0][1].as<std::string>();
        std::string client_surname = res[0][2].as<std::string>();
        std::cout << "Phone removed for client: " << client_id << " " << client_name << " " << client_surname << std::endl;
    }
    else
    {
        transaction_base.abort();
        std::cerr << "Client not found: " << email << std::endl;
    }
}

void DataBase::removeClient(const std::string& email) 
{
    pqxx::work transaction_base(connection_);
    pqxx::result res = transaction_base.exec_params("SELECT id, name, surname FROM clients WHERE email = $1", email);
    if (!res.empty()) {
        int client_id = res[0][0].as<int>();
        std::string client_name = res[0][1].as<std::string>();
        std::string client_surname = res[0][2].as<std::string>();
        transaction_base.exec_params("DELETE FROM phones WHERE client_id = $1", client_id);
        transaction_base.exec_params("DELETE FROM clients WHERE id = $1", client_id);
        transaction_base.commit();
        std::cout << "Client removed: " << client_id << " " << client_name << " " << client_surname << std::endl;
    }
    else {
        transaction_base.abort();
        std::cerr << "Client not found: " << email << std::endl;
    }
}

std::vector<Client> DataBase::findClients(const std::string& query)
{
    std::vector<Client> result;
    pqxx::work transaction_base(connection_);
    pqxx::result res = transaction_base.exec_params(
        "SELECT * "
        "FROM clients "
        "LEFT JOIN public.phones on public.clients.id = public.phones.client_id "
        "WHERE clients.name = $1 OR clients.surname = $1 OR clients.email = $1 OR phones.phone = $1;", query);
    transaction_base.commit();
    for (auto row : res) {
        Client client;
        client.name_client = row["name"].as<std::string>();
        client.surname_client = row["surname"].as<std::string>();
        client.email_client = row["email"].as<std::string>();
        result.push_back(client);
    }
    return result;
}

void DataBase::showBD()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    pqxx::work transaction_base(connection_);
    pqxx::result tables = transaction_base.exec("SELECT table_name FROM information_schema.tables WHERE table_schema='public'");
    for (auto row : tables)
    {
        std::string table_name = row[0].as<std::string>();
        std::string query = "SELECT * FROM " + table_name;
        pqxx::result data = transaction_base.exec(query);
        std::cout << "Table: " << table_name << std::endl;
        for (auto& row : data) {
            for (auto& field : row) {
                std::cout << field.c_str() << "  ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    transaction_base.commit();
    std::cout << "Done" << std::endl;
};