#include "bikewindow.h"

#include <QVBoxLayout>

bikeWindow::bikeWindow(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *myQVBox = new QVBoxLayout(this);
    this->resize(1500,1000);
    this->setLayout(myQVBox);
}
