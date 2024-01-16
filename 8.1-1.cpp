// 8.1-1.cpp : 

#include "iostream"

struct Query {
    std::string column;
    std::string from;
    std::string where;
};

class SqlSelectQueryBuilder {
public:
    explicit SqlSelectQueryBuilder() {
    }

    std::string BuildQuery() noexcept {
        std::string query_string;
        if (query.column.empty()) query_string += "SELECT *";
        else query_string += query.column;
        query_string += query.from;
        query_string += query.where;
        query_string += ";";
        return query_string;
    }
    SqlSelectQueryBuilder& AddColumn(const std::string& col) {
        if (query.column.empty()) query.column = "SELECT " + col;
        else query.column += ", " + col;
        return *this;
    }

    SqlSelectQueryBuilder& AddFrom(const std::string& from_add) {
        query.from = " FROM " + from_add;
        return *this;
    }
    SqlSelectQueryBuilder& AddWhere(const std::string& variable, const std::string& value) {
        if (query.where.empty()) query.where = " WHERE " + variable + " = " + value;
        else query.where += " AND " + variable + " = " + value;
        return *this;
    }
private:
    Query query;
};



int main() {
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");

    std::cout << query_builder.BuildQuery();
}