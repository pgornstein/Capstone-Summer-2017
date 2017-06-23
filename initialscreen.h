#ifndef INITIALSCREEN_H
#define INITIALSCREEN_H

#include "QWidget"
#include <QPushButton>

class initialScreen : public QWidget
{
    Q_OBJECT
public:
    explicit initialScreen(QWidget *parent = 0);

private:
    int getNumberOfBikes();
    void manageBikes();
};

#endif // INITIALSCREEN_H
