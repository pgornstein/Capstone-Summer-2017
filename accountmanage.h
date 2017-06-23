#ifndef ACCOUNTMANAGE_H
#define ACCOUNTMANAGE_H

#include <QWidget>
#include <QVBoxLayout>

class accountManage : public QWidget
{

public:
    explicit accountManage(QWidget *parent = 0);
private:
    QVBoxLayout *myQVBox;

    void addNewBike();
    void searchForBike();
    void displayStatistics();

};

#endif // ACCOUNTMANAGE_H
