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

private slots:
    void checkBikeID();

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

    int bikeID;
    bool inService;

    void displayBikeInfo();
    void enterCheckinData();
    void copyCheckInData();
    void backToManagePage();
    void checkInService();
    void toggleInService();
    void setHealth();
    void changeHealth();


    // Test functions
    void testEnterCheckinData();
};

#endif // BIKEWINDOW_H
