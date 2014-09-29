#ifndef STYLESHEETS_H
#define STYLESHEETS_H

#include <QString>

#include "ui_mainwindow.h"

class Stylesheet;

class Stylesheets
{
public:
    Stylesheets();
    void removeStylesheet(QString path);
    void addStylesheetFromFile(QString path);
    void addStylesheetFromUrl(QString path);
    void addToWidget(QString path);
    void moveStyleUp(QString path);
    void add(Stylesheet style);
    void update();
    QString getStylesheets();
    QString createStylesheetLink(QString path);

private:
    QVector< QVector<QString> > stylesList;
    QString cssStyle;
    void updateList();
    void updateCss();
};

class Stylesheet
{
public:
    Stylesheet(QString path, QString link);
    QString path;
    QString link;
};

#endif // STYLESHEETS_H
