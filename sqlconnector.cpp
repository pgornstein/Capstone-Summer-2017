#include "sqlconnector.h"
#include <QDebug>
#include <QtSql/QSqlError>

sqlConnector::sqlConnector()
{
       db = QSqlDatabase::addDatabase("QMYSQL");
       db.setHostName("capstone-bikes.cphpxguj45gw.us-east-1.rds.amazonaws.com");
       db.setUserName("db_admin");
       db.setPassword("capstone");
       db.setPort(3306);
       db.setDatabaseName("Capstone_Bike_Shop");
       if(!db.open()) {
              QSqlError err = db.lastError();
              qDebug() << err.text();
       }
       //QSqlQuery query("INSERT INTO Master (BikeId, CheckedOut, Service, Distance, Health) VALUES (2, 0, 0, 0, 10);",db);
        query = new QSqlQuery(db);
}

sqlConnector::~sqlConnector() {
    db.close();
    query.finish();
}
