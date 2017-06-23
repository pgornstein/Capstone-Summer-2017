#include "initialscreen.h"
#include "mainwindow.h"

#include <QLabel>
#include <QFont>
#include <QVBoxLayout>
#include <QMessageBox>

initialScreen::initialScreen(QWidget *parent) : QWidget(parent)
{

    this->setWindowTitle("Capstone Bikes");
    QLabel *welcomeMessage =  new QLabel();
    QFont font("Arial",22,QFont::Bold);
    welcomeMessage->setText("Capstone Bikes");
    welcomeMessage->setFont(font);

    QLabel *version = new QLabel();
    version->setText("Alpha v1.01");

    QVBoxLayout *myQVBox = new QVBoxLayout(this);

    myQVBox->addWidget(welcomeMessage);
    myQVBox->addWidget(version);

    QPushButton *manage = new QPushButton();
    manage->setText("Manage Bikes");
    myQVBox->addWidget(manage);

    QPushButton *aboutUs = new QPushButton();
    aboutUs->setText("About us");
    myQVBox->addWidget(aboutUs);

    connect(manage, &QPushButton::released, this, &initialScreen::manageBikes);
    connect(aboutUs, &QPushButton::released, this, &initialScreen::displayAboutUs);

}

int initialScreen::getNumberOfBikes() {
    // Search database and return the number of bikes in the system
}

void initialScreen::manageBikes() {

    MainWindow *main = new MainWindow;
    hide();
    main->show();
}

void initialScreen::displayAboutUs() {
    QMessageBox *us = new QMessageBox();
    QString project("Bike rental service created for our capstone class\n\n");
    us->setText(project + "Adam Ovadia\nLiam Hayes\nPhillip Gornstein\nTasdique Chowdhury\nVlad Shostak");
    us->show();
}
