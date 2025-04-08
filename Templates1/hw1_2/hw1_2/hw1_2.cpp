#include "sql_query_builder.h"
#include <iostream>

int main() {
    SqlSelectQueryBuilder query_builder;

    query_builder.AddColumns({ "name", "email", "phone" })  
        .AddFrom("users") 
        .AddWhere("age", "25")  
        .AddWhere({ {"status", "active"},
                  {"country", "RU"} });

    std::cout << query_builder.BuildQuery() << std::endl;

    return 0;
}