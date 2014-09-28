#ifndef TABS_H
#define TABS_H

#include <QString>
#include <QVector>

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
        Tab(QString title = "untitled", QString text = "");
        QString title;
        QString text;
        QVector< QVector<QString> > stylesList;

        void close();
        void index();
};

#endif // TABS_H
