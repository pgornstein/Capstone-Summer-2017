#include "bikewindow.h"
#include "accountmanage.h"
#include <QDebug>
#include <QMessageBox>
#include <QSpacerItem>
#include <QClipboard>
#include <QApplication>
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
    QLabel *id = new QLabel("Bike ID: " +QString::number(bikeID));

    myQVBox->addWidget(id);
    myQVBox->addWidget(checkin);

    myList = new QListWidget(this);
    myList->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    myQHBox->addWidget(myList);
    myQHBox->addSpacerItem(horiSpace);

    myQVBox->addLayout(myQHBox);

    QSpacerItem *vertSpace = new QSpacerItem(2,200, QSizePolicy::Expanding, QSizePolicy::Expanding);
    myQVBox->addSpacerItem(vertSpace);

    serviced = new QLabel();
    checkInService();
    if (inService) {
        serviced->setText("Bike is being serviced");
    } else {
        serviced->setText("Bike is active");
    }
    myQVBox->addWidget(serviced);

    QPushButton *toggleServiced = new QPushButton("Toggle serviced status");
    myQVBox->addWidget(toggleServiced);
    testEnterCheckinData();
    // Double press checkin data to copy item to clipboard
    connect(myList, &QListWidget::doubleClicked, this, &bikeWindow::copyCheckInData);
    connect(toggleServiced, &QPushButton::released, this, &bikeWindow::toggleInService);


  //  QHBoxLayout *backLayout = new QHBoxLayout();
  //  QPushButton *backButton = new QPushButton("Back");
   // backLayout->addSpacerItem(horiSpace);
   // backLayout->addWidget(backButton);
    //myQVBox->addLayout(backLayout);

   // connect(backButton, &QPushButton::released, this, &bikeWindow::backToManagePage);
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

void bikeWindow::backToManagePage() {
    hide();
    accountManage *mManage = new accountManage();
    mManage->show();
}

// Method to copy item to clipboard
void bikeWindow::copyCheckInData() {
    int pos = myList->currentRow();
    qDebug() <<"pos: " <<QString::number(pos);
    QClipboard *copyItem = QApplication::clipboard();
    copyItem->setText(myList->currentItem()->text());

}

void bikeWindow::checkInService() {
    // Using BikeID, check server to see if bike is in service
    // set 'inService' bool to true/false
}

void bikeWindow::toggleInService() {
    if (inService) {
        serviced->setText("Bike is active");
        inService = false;
    } else {
        serviced->setText("Bike is being serviced");
        inService = true;
    }

    // Reflect change in server
}
