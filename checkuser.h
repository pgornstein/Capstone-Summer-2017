#ifndef CHECKUSER_H
#define CHECKUSER_H

#include <QString>
#include <string>
#include <QtSql/QSqlQuery>

class checkUser
{
public:
    checkUser(QString, QString);
    ~checkUser();
    bool isAccountFound() const;
     void queryAccess(QSqlQuery *a);

private:
    std::string name, password;
    QString generateHash(const char *data);
     QSqlQuery *query;

};

#endif // CHECKUSER_H
