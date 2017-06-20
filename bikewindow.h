#ifndef BIKEWINDOW_H
#define BIKEWINDOW_H
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>


class bikeWindow : public QWidget
{
    Q_OBJECT
public:
    explicit bikeWindow(QWidget *parent = 0);
    void setupBikeWindow();

private slots:
    void checkBikeID();

private:
    QLineEdit *editBikeID;
    QLabel *enterBikeID;
    QPushButton *acceptBikeID;

    int bikeID;

    void displayBikeInfo();

};

#endif // BIKEWINDOW_H
