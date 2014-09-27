#ifndef UTILITIES_H
#define UTILITIES_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QResource>
#include <QVector>

#include "ui_mainwindow.h"
#include "tabs.h"
#include "stylesheets.h"
#include "markdown.h"

class Utilities
{
public:
    Utilities();
    QString prepareHtml(QString styles, QString input);
    QString getResource(QString path);
    QString htmlTemplate;
    Ui::MainWindow *ui;
    QVector<Tab*> tabsList;
private:
    QString parseTemplate();
};

extern Utilities commonUtils;

#endif // UTILITIES_H
