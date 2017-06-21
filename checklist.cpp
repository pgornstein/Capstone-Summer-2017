#include "checklist.h"

checkList::checkList(QWidget *parent, int id)
{
    bikeID = id;
    myListView = new QListWidget(this);

    setParent(parent);
}

void checkList::addRow(QString item) {
    myListView->addItem(item);
}

void checkList::fillRowsFromServer() {

    /* TODO
     * Get Check in/out data from server
     * call addRow(QString) to add data to the listWidget
     */


}
