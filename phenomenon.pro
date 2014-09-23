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

SUBDIRS += sundown
sundownlib.makefile = sundown/Makefile

QMAKE_EXTRA_TARGETS += sundown

LIBS += -Llibs/hoedown -lhoedown

SOURCES += main.cpp\
        mainwindow.cpp \
    theme.cpp \
    utilities.cpp \
    stylesheets.cpp \
    markdown.cpp

HEADERS  += mainwindow.h \
    theme.h \
    utilities.h \
    stylesheets.h \
    markdown.h

FORMS    += mainwindow.ui

RESOURCES += \
    Resources.qrc

OTHER_FILES += \
    icons/file.png
