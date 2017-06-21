#include "bikewindow.h"

#include <QDebug>
#include <QMessageBox>
#include <QSpacerItem>
bikeWindow::bikeWindow(QWidget *parent) : QWidget(parent)
{
    setupBikeWindow();
}

void bikeWindow::setupBikeWindow() {
    myQVBox = new QVBoxLayout(this);
    this->resize(400,400);

    enterBikeID = new QLabel();
    enterBikeID->setText("Enter Bike ID");
    enterBikeID->setAlignment(Qt::AlignCenter);


    myQVBox->addWidget(enterBikeID);

    editBikeID = new QLineEdit();
    editBikeID->setAlignment(Qt::AlignCenter);

    myQVBox->addWidget(editBikeID);


    acceptBikeID = new QPushButton();
    acceptBikeID->setText("Enter");


    myQVBox->addWidget(acceptBikeID);


    this->setLayout(myQVBox);

    //When 'Enter' button is pressed, run 'checkBikeID'
    connect(acceptBikeID, &QPushButton::released, this, &bikeWindow::checkBikeID);
}

void bikeWindow::checkBikeID() {
    qDebug() <<"You pressed the accept button!";
    bool isValidInput;
    bikeID = editBikeID->text().toUInt(&isValidInput, 10);
    qDebug() <<"Bike ID: " <<bikeID;
    if (!isValidInput) {
        QMessageBox::warning(this, "Error", "Invalid Character!");
    } else {
        // Check sql server for matching bike id

        displayBikeInfo();
    }


}

void bikeWindow::displayBikeInfo() {
    this->resize(1500,1000);
    // Delete objects from window
    delete editBikeID;
    delete acceptBikeID;
    delete enterBikeID;

    myQHBox = new QHBoxLayout();
    QSpacerItem *horiSpace = new QSpacerItem(300,2, QSizePolicy::Expanding, QSizePolicy::Expanding);

    QLabel *checkin = new QLabel("Checkin / Checkout info",this);

    myQVBox->addWidget(checkin);

    myList = new QListWidget(this);
    myList->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    myQHBox->addWidget(myList);
    myQHBox->addSpacerItem(horiSpace);

    myQVBox->addLayout(myQHBox);

    QSpacerItem *vertSpace = new QSpacerItem(2,200, QSizePolicy::Expanding, QSizePolicy::Expanding);
    myQVBox->addSpacerItem(vertSpace);
}

void bikeWindow::enterCheckinData() {
    /* TODO
     * Get Check in/out data from server
     * add Items to 'myList' using the addItem() or addItems() method
     */
}



void bikeWindow::testEnterCheckinData() {
    myList->addItem("Out: 2/2/17 5:30am");
    myList->addItem("In: 2/2/17 7:45am");
    myList->addItem("Out: 2/2/17 5:30am");
    myList->addItem("In: 2/2/17 7:45am");
    myList->addItem("Out: 2/2/17 5:30am");
    myList->addItem("In: 2/2/17 7:45am");
}
