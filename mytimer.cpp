#include "mytimer.h"
#include <QTimer>
#include <QDateTime>

myTimer::myTimer()
{
    tElapsedLbl = new QLabel();
    ElapsedTimeLbl = new QLabel("Time Elapsed");
    ElapsedTimeLbl->setFont(QFont("Times", 16, QFont::Bold));
    myQVBox = new QVBoxLayout();

    QTimer *time = new QTimer();
    connect(time, &QTimer::timeout, this, &myTimer::updateTimer);
    time->start(1000);

    myQVBox->addWidget(ElapsedTimeLbl);
    myQVBox->addWidget(tElapsedLbl);
    myQVBox->setAlignment(Qt::AlignLeft);

    setLayout(myQVBox);
}

void myTimer::updateTimer() {
    tElapsedLbl->setText(QString(QDateTime::fromTime_t(tElapsed).toUTC().toString("hh:mm:ss")));
    tElapsed++;
}

void myTimer::setData(double val) {
    tElapsed  = val;
    tElapsedLbl->setText(QString(QDateTime::fromTime_t(val).toUTC().toString("hh:mm:ss")));
}
