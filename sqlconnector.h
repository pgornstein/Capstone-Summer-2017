#ifndef SQLCONNECTOR_H
#define SQLCONNECTOR_H

#include <QtSql/QSqlDatabase>

class sqlConnector
{
public:
    sqlConnector();

private:
    QSqlDatabase db;
};

#endif // SQLCONNECTOR_H
