#ifndef CHECKINHISTORY_H
#define CHECKINHISTORY_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QListWidget>
#include <QtSql/QSqlQuery>
class checkInHistory : public QWidget
{
    Q_OBJECT
public:
    explicit checkInHistory(const int id);
    void testEnterCheckinData();
    void setData(std::vector<std::string>);
    void setToggled(QDateTime, bool);
    void sendQuery(QSqlQuery);

private slots:
    void copyCheckInData();

private:
    int bikeID;
    QVBoxLayout *myQVBox;
    QListWidget *myList;
    QSqlQuery query;
};

#endif // CHECKINHISTORY_H
