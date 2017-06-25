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
    void copyCheckInData();

private:
    QLineEdit *editBikeID;
    QLabel *enterBikeID;
    QPushButton *acceptBikeID;
    QVBoxLayout *myQVBox;
    QHBoxLayout *myQHBox;
    QHBoxLayout *myQHBox4;
    QListWidget *myList;
    int bikeID;

    void displayBikeInfo();
    void enterCheckinData();
    void backToManagePage();

    // Test functions
    void testEnterCheckinData();
};

#endif // BIKEWINDOW_H
