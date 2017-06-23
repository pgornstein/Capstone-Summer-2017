#include "initialscreen.h"
#include "mainwindow.h"

#include <QLabel>
#include <QFont>
#include <QVBoxLayout>

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


    connect(manage, &QPushButton::released, this, &initialScreen::manageBikes);


}

int initialScreen::getNumberOfBikes() {
    // Search database and return the number of bikes in the system
}

void initialScreen::manageBikes() {

    MainWindow *main = new MainWindow;
    hide();
    main->show();
}
