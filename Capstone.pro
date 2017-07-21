#-------------------------------------------------
#
# Project created by QtCreator 2017-06-16T20:28:18
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Capstone
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        checkuser.cpp \
        bikewindow.cpp \
        accountmanage.cpp \
        initialscreen.cpp \
        mytimer.cpp \
        rentaltimewidget.cpp \
        checkoutwidget.cpp \
        bikehealth.cpp \
        bikeserviced.cpp \
        checkinhistory.cpp

HEADERS += \
        mainwindow.h \
        checkuser.h \
        bikewindow.h \
        accountmanage.h \
        initialscreen.h \
        mytimer.h \
        rentaltimewidget.h \
        checkoutwidget.h \
        bikehealth.h \
        bikeserviced.h \
        checkinhistory.h

FORMS += \
        mainwindow.ui

RESOURCES += \
        res.qrc
