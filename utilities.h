#ifndef UTILITIES_H
#define UTILITIES_H

#include "ui_mainwindow.h"
#include "markdown.h"
#include "tabs.h"

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
