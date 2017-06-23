#include "accountmanage.h"
#include "bikewindow.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QDebug>

accountManage::accountManage(QWidget *parent) : QWidget(parent)
{
    myQVBox = new QVBoxLayout(this);
    this->resize(800,500);
    setWindowTitle("Account Management");

    QHBoxLayout *myQHBox = new QHBoxLayout();
    QHBoxLayout *myQHBox2 = new QHBoxLayout();
    QHBoxLayout *myQHBox3 = new QHBoxLayout();

    QSpacerItem *mySpacer = new QSpacerItem(400,2);



    QPushButton *newBike = new QPushButton();
    QPushButton *searchBike = new QPushButton();
    QPushButton *statBike = new QPushButton();

    newBike->setText("Add a new Bike");
    searchBike->setText("Search for a Bike");
    statBike->setText("Bike statistics");


    myQHBox->addSpacerItem(mySpacer);
    myQHBox->addWidget(newBike);

    myQHBox2->addSpacerItem(mySpacer);
    myQHBox2->addWidget(searchBike);

    myQHBox3->addSpacerItem(mySpacer);
    myQHBox3->addWidget(statBike);

    myQVBox->addLayout(myQHBox);
    myQVBox->addLayout(myQHBox2);
    myQVBox->addLayout(myQHBox3);

    setLayout(myQVBox);

    connect(newBike, &QPushButton::released,this, &accountManage::addNewBike);
    connect(searchBike, &QPushButton::released, this, &accountManage::searchForBike);
    connect(statBike, &QPushButton::released, this, &accountManage::displayStatistics);

}

void accountManage::addNewBike() {

}

void accountManage::searchForBike() {
    bikeWindow *myBikeWindow = new bikeWindow();
    hide();
    myBikeWindow->show();
}

void accountManage::displayStatistics() {

}
