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

INCLUDEPATH += libs/hoedown/src

unix {
    LIBS += -Llibs/hoedown -lhoedown
}
win32 {
    LIBS += -lhoedown
}

SOURCES +=  src/main.cpp\
            src/mainwindow.cpp \
            src/theme.cpp \
            src/utilities.cpp \
            src/stylesheets.cpp \
            src/markdown.cpp \
            src/tabs.cpp

HEADERS  += src/mainwindow.h \
            src/theme.h \
            src/utilities.h \
            src/stylesheets.h \
            src/markdown.h \
            src/tabs.h

FORMS    += src/mainwindow.ui

RESOURCES+= resources/Resources.qrc
