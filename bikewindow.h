#ifndef BIKEWINDOW_H
#define BIKEWINDOW_H
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QSlider>
#include <QProgressBar>


class bikeWindow : public QWidget
{
    Q_OBJECT
public:
    explicit bikeWindow(QWidget *parent = 0);
    void setupBikeWindow();

public slots:
    void updateTimer();

private slots:
    void checkBikeID();
    void copyCheckInData();
    void toggleInService();
    void toggleCheckOut();

private:
    QLineEdit *editBikeID;
    QLabel *enterBikeID;
    QPushButton *acceptBikeID;
    QVBoxLayout *myQVBox;
    QHBoxLayout *myQHBox;
    QHBoxLayout *myQHBox4;
    QListWidget *myList;
    QLabel *serviced;
    QSlider *healthSlider;
    QProgressBar *healthBar;
    QLabel *checkOut;
    QLabel *rentalTimeUpdateLbl;
    QLabel *tElapsedLbl;

    int bikeID;
    bool inService;
    bool isCheckedOut;
    int tElapsed;

    void displayBikeInfo();
    void enterCheckinData();
    void backToManagePage();
    void checkInService();
    void setHealth();
    void changeHealth();
    int setTimeElapsed();

    QString getCheckOutData();
    QString getRentalTime();

    // Test functions
    void testEnterCheckinData();
};

#endif // BIKEWINDOW_H
