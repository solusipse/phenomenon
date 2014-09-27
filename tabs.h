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
};

class Tab
{
    public:
        Tab(QString title = "untitled");
        QString title;
        QString contents;
        QVector< QVector<QString> > stylesList;

        void close();
        void index();
};

#endif // TABS_H
