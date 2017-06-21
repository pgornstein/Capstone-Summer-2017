#ifndef CHECKLIST_H
#define CHECKLIST_H

#include <QWidget>
#include <QListWidget>

class checkList : public QWidget
{
public:
    checkList(QWidget *parent, int id);
    void fillRowsFromServer();


private:
    int bikeID;
    QListWidget *myListView;

    void addRow(QString);

};

#endif // CHECKLIST_H
