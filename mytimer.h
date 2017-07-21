#ifndef MYTIMER_H
#define MYTIMER_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class myTimer : public QWidget
{
    Q_OBJECT

public:
    explicit myTimer();
    void setData(double);

public slots:
    void updateTimer();

private:
    QLabel *ElapsedTimeLbl;
    QLabel *tElapsedLbl;
    QVBoxLayout *myQVBox;
    double tElapsed;
};

#endif // MYTIMER_H
