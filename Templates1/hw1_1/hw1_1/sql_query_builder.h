#ifndef SQL_QUERY_BUILDER_H
#define SQL_QUERY_BUILDER_H

#include <string>
#include <vector>
#include <map>

class SqlSelectQueryBuilder {
public:
    SqlSelectQueryBuilder() = default;

    // Добавление столбцов
    SqlSelectQueryBuilder& AddColumn(const std::string& column);
    SqlSelectQueryBuilder& AddFrom(const std::string& table);
    SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value);

    // Построение SQL-запроса
    std::string BuildQuery() const;

private:
    std::vector<std::string> columns_;
    std::string table_;
    std::map<std::string, std::string> where_conditions_;
};

#endif // SQL_QUERY_BUILDER_H