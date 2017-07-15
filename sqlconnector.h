#ifndef SQLCONNECTOR_H
#define SQLCONNECTOR_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>


class sqlConnector
{
public:
    sqlConnector();
    ~sqlConnector();

private:
    QSqlDatabase db;
    QSqlQuery query;
};

#endif // SQLCONNECTOR_H
