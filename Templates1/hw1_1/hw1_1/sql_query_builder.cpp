#include "sql_query_builder.h"

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::string& column) {
    columns_.push_back(column);
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string& table) {
    table_ = table;
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string& column, const std::string& value) {
    where_conditions_[column] = value;
    return *this;
}

std::string SqlSelectQueryBuilder::BuildQuery() const {
    std::string query = "SELECT ";

    if (columns_.empty()) {
        query += "*";
    }
    else {
        for (size_t i = 0; i < columns_.size(); ++i) {
            if (i != 0) {
                query += ", ";
            }
            query += columns_[i];
        }
    }

    if (!table_.empty()) {
        query += " FROM " + table_;
    }

    if (!where_conditions_.empty()) {
        query += " WHERE ";
        bool first = true;
        for (const auto& [column, value] : where_conditions_) {
            if (!first) {
                query += " AND ";
            }
            query += column + "=" + value;
            first = false;
        }
    }

    query += ";";
    return query;
}