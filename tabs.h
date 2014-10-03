#ifndef TABS_H
#define TABS_H

#include <QString>
#include <QVector>
#include <QTextCursor>

#include "stylesheets.h"

class Tab;

class Tabs
{
    public:
        Tabs();
        void close(int i);
        void addToTabsList(Tab *t);
        int currentIndex();
        Tab *current();
        Tab *add();
        Tab *fromIndex(int i);
};

class Tab
{
    public:
        Tab(QString title = "untitled", QString text = "", QString path = "");
        QString title;
        QString text;
        QString path;
        /* Cursor position has to be int for now
         * due to QT bug. TODO: make QTextCursor instance
         * for doing it in the future, when
         * that bug will be fixed */
        int cursorPosition;
        int scrollPosition;
        int maxScrollPosition;

        //bool modified = false;
        QVector< Stylesheet* > styles;

        void close();
        void index();
        void update();
        int id();
};

#endif // TABS_H
