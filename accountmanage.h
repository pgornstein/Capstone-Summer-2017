#ifndef ACCOUNTMANAGE_H
#define ACCOUNTMANAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include "bikewindow.h"
#include <QtSql/QSqlQuery>

class accountManage : public QWidget
{

public:
    explicit accountManage(QWidget *parent = 0);
    void queryAccess(QSqlQuery *a);
private:
    QVBoxLayout *myQVBox;
    QHBoxLayout *myQHBox4;
    bikeWindow *myBikeWindow;
    bikeWindow *myBikeWindow2;
    bikeWindow *myBikeWindow3;
    QSqlQuery *query;


    void addNewBike();
    void searchForBike();
    void displayStatistics();
    bool isBikeWindowActive;
    bool isAddBikeActive;
    bool isStatisticsActice;
    void removeActiveWindows();
};

#endif // ACCOUNTMANAGE_H

