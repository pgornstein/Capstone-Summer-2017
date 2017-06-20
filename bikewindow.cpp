#include "bikewindow.h"

#include <QVBoxLayout>
#include <QDebug>
#include <QMessageBox>

bikeWindow::bikeWindow(QWidget *parent) : QWidget(parent)
{
    setupBikeWindow();
}

void bikeWindow::setupBikeWindow() {
    QVBoxLayout *myQVBox = new QVBoxLayout(this);
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

}
