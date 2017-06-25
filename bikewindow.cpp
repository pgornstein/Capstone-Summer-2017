#include "bikewindow.h"
#include "accountmanage.h"
#include "mytimer.h"
#include "rentaltimewidget.h"
#include "checkoutwidget.h"
#include "bikehealth.h"
#include "bikeserviced.h"
#include <QDebug>
#include <QMessageBox>
#include <QSpacerItem>
#include <QClipboard>
#include <QApplication>
#include <QTimer>
#include <QDateTime>

bikeWindow::bikeWindow(QWidget *parent) : QWidget(parent)
{
    setupBikeWindow();
}

void bikeWindow::setupBikeWindow() {
    myQHBox = new QHBoxLayout(this);
    myQVBox = new QVBoxLayout();
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
    myQHBox->addLayout(myQVBox);

    this->setLayout(myQHBox);

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

    QLabel *checkin = new QLabel("Checkin / Checkout info",this);
    QLabel *id = new QLabel("Bike ID: " +QString::number(bikeID));
    id->setFont(QFont("Times", 16, QFont::Bold));
    id->setAlignment(Qt::AlignHCenter);
    id->setStyleSheet("border:5px solid #000000");
    checkin->setFont(QFont("Times", 16, QFont::Bold));
    myQVBox->addWidget(id);
    myQVBox->addWidget(checkin);

    myList = new QListWidget(this);
    myList->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    myQVBox->addWidget(myList);
   // myQHBox->addSpacerItem(horiSpace);
    testEnterCheckinData();

    QSpacerItem *vertSpace = new QSpacerItem(200,2, QSizePolicy::Expanding, QSizePolicy::Expanding);
   // myQVBox->addSpacerItem(vertSpace);

    QVBoxLayout *QVBHealth = new QVBoxLayout();
    myQHBox->addLayout(QVBHealth);

    bikeServiced *myBikeSeviced = new bikeServiced();
    myQVBox->addWidget(myBikeSeviced);

    checkOutWidget *myCheckOut = new checkOutWidget();
    myQVBox->addWidget(myCheckOut);

    bikeHealth *myBikeHealth = new bikeHealth();
    QVBHealth->addWidget(myBikeHealth);

    rentalTimeWidget *myRentalTime = new rentalTimeWidget();
    QVBHealth->addWidget(myRentalTime);

    myTimer *myTimerLayout = new myTimer();
    QVBHealth->addWidget(myTimerLayout);
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
