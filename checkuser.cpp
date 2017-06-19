#include "checkuser.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QVector>

checkUser::checkUser()
{

}

void checkUser::enterUsrNamePassword(QString mName, QString mPassword) {
    name = mName.toStdString();
    const char * tempPass = mPassword.toStdString().c_str();
    QString encryptPass = generateHash(tempPass);
    password = encryptPass.toStdString();
}

bool checkUser::isAccountFound() {

    //  std::string name, password; check server against these values
    // return true if account is found using sql queries
    return "63939540b5a5aadf20920ba5558ed7d089e265d48d16152d00fa47f5fe827d43" == password;
}

QString checkUser::generateHash(const char *data) {
    QCryptographicHash *userPass = new QCryptographicHash(QCryptographicHash::Sha256);
    userPass->addData(data, strlen(data));
    qDebug() <<"generated pass: " <<userPass->result().toHex();
    return userPass->result().toHex();
}

