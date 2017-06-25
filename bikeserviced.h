#ifndef BIKESERVICED_H
#define BIKESERVICED_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class bikeServiced : public QWidget
{
    Q_OBJECT
public:
    explicit bikeServiced();

private slots:
    void toggleInService();

private:
    QLabel *serviced;
    int bikeID;
    bool inService;
    QVBoxLayout *myQVBox;
    void checkInService();

};

#endif // BIKESERVICED_H
