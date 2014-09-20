#-------------------------------------------------
#
# Project created by QtCreator 2014-09-20T04:10:44
#
#-------------------------------------------------

QT       += core gui
QT       += webkit webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = phenomenon
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    theme.cpp \
    utilities.cpp

HEADERS  += mainwindow.h \
    theme.h \
    utilities.h

FORMS    += mainwindow.ui

RESOURCES += \
    Resources.qrc
