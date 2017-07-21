#ifndef RENTALTIMEWIDGET_H
#define RENTALTIMEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QString>
#include <QComboBox>
#include <QDialog>

class rentalTimeWidget : public QWidget
{
    Q_OBJECT
public:
   explicit rentalTimeWidget();
    void setData(double);

private slots:
    void setRentalTime();
    void saveRentalTime();

private:
    QLabel *rentalTimeUpdateLbl;
    QVBoxLayout *myQVBox;
    QString getRentalTime();
    QComboBox *mComboBox;
    QDialog *mDialog;
};

#endif // RENTALTIMEWIDGET_H
