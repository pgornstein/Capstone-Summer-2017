#include "checkinhistory.h"
#include <QDebug>
#include <QClipboard>
#include <QApplication>
#include <QDateTime>

checkInHistory::checkInHistory(const int id)
{
    bikeID = id;
    myQVBox = new QVBoxLayout();
    QLabel *checkin = new QLabel("Checkin / Checkout info",this);
    checkin->setFont(QFont("Times", 16, QFont::Bold));

    myQVBox->addWidget(checkin);

    myList = new QListWidget(this);
    myList->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    myQVBox->addWidget(myList);
   // myQHBox->addSpacerItem(horiSpace);
    setLayout(myQVBox);
}

// Method to copy item to clipboard
void checkInHistory::copyCheckInData() {
    int pos = myList->currentRow();
    qDebug() <<"pos: " <<QString::number(pos);
    QClipboard *copyItem = QApplication::clipboard();
    copyItem->setText(myList->currentItem()->text());

}

void checkInHistory::testEnterCheckinData() {
    myList->addItem("Out: 2/2/17 5:30am");
    myList->addItem("In: 2/2/17 7:45am");
    myList->addItem("Out: 2/2/17 5:30am");
    myList->addItem("In: 2/2/17 7:45am");
    myList->addItem("Out: 2/2/17 5:30am");
    myList->addItem("In: 2/2/17 7:45am");
}

void checkInHistory::setData(std::vector<std::string> data) {
    for (unsigned int a = 0; a < data.size(); a++) {
        QString val(data[a].c_str());
        if (val[val.size()] == 'I') {
            val.remove(val.size(), 1);
            myList->addItem(val.append(" in"));
        } else {
            myList->addItem(val.append(" out"));
        }
    }
}

void checkInHistory::setToggled(QDateTime mTime, bool mServiced) {
    if (mServiced) {
        myList->addItem(mTime.toString("dd.MM.yyyy hh:mm:ss").append(" out"));
        // Add to server
    } else {
        myList->addItem(mTime.toString("dd.MM.yyyy hh:mm:ss").append(" in"));
        // Add to server
    }
}

void checkInHistory::sendQuery(QSqlQuery a) {
    query = a;
}
