#include <iostream>
#include "clients_sql.h"

int main()
{
    try
    {
        std::string connection_string = "host=127.0.0.1 port=5432 dbname=clients user=postgres password=9768213";
        DataBase db(connection_string);

        db.createTables();

        db.addNewClient("Nata", "Kranovid", "Nata@yandex.ru", "98513264521");
        db.showBD();


        db.addNewClient("Victor", "Petrov", "Vit@mail.ru", "98546521245");
        db.showBD();

        db.addNewClient("Nataly", "Ivanova", "Nata2@yandex.ru", "98253652145");
        db.showBD();

        db.addNewClient("Petr", "Sidorov", "Pit@mail.ru", "95462513652");
        db.showBD();

        db.addNewClient("Natanata", "Kras1", "Nata@yandex.ru2", "985132645212");
        db.showBD();

        db.addPhone("Nataly", "86523562211");
        db.showBD();
      
        db.updateClient("Vit@mail.ru", "Victor2", "PetrovPetrov", "Vit1@mail.runew");
        db.showBD();
      
        db.removePhone("Vit@mail.ru", "1254658956");

        db.removeClient("Nata@yandex.ru2");

        std::vector<Client> foundClients = db.findClients("Nataly");
        for (const auto& client : foundClients)
        {
            std::cout << "Found client: " << client.name_client << " " << client.surname_client << " " << client.email_client << " " << std::endl;
        }

    }
    catch (const std::exception& ex)
    {
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
        std::cout << "Exception happened: " << ex.what() << std::endl;
    }
}