#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "checkuser.h"
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString imgPath = ":/Res/Res/bike.png";
    QImage image(imgPath);
    ui->imgView->setPixmap(QPixmap::fromImage(image));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cancelButton_released()
{
    QApplication::quit();
}

void MainWindow::on_loginButton_released()
{
    checkUser *isUPValid = new checkUser();
    isUPValid->enterUsrNamePassword(ui->usernameTxt->text(), ui->passwordTxt->text());
    if (isUPValid->isAccountFound()) {
        qDebug() <<"Success!";
        QMessageBox *EULA = new QMessageBox();
        EULA->setText("This is the End User License Agreement \n Capstone does not come with warrenty!");
        EULA->show();
    }

}