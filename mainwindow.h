#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlQuery>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_cancelButton_released();

    void on_loginButton_released();

private:
    QSqlQuery *query;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
