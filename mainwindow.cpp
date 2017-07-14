#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "checkuser.h"
#include "bikewindow.h"
#include "accountmanage.h"
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString imgPath = ":/Res/Res/logo.jpg";
    QImage image(imgPath);
    ui->imgView->setPixmap(QPixmap::fromImage(image));

}

MainWindow::~MainWindow()
{
    delete ui;
}

// Quits application when Quit button is released
void MainWindow::on_cancelButton_released()
{
    QApplication::quit();
}


// Checks user entered account info when login button is pressed
void MainWindow::on_loginButton_released()
{
    checkUser *isUPValid = new checkUser(ui->usernameTxt->text(), ui->passwordTxt->text());
    if (isUPValid->isAccountFound()) {
        qDebug() <<"Success!";
        hide();
        accountManage *myManage = new accountManage();
        myManage->show();
    } else { /* Display error message on status bar */
        ui->statusBar->showMessage("Invalid Username and/or Password!", 3000);
        ui->passwordTxt->clear();
    }
}
