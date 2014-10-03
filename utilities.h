#ifndef UTILITIES_H
#define UTILITIES_H

#include "ui_mainwindow.h"
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
    QString getFileContents(QString path);
    QString getFileName(QString path);

private:
    QString parseTemplate();
};

extern Utilities commonUtils;

#endif // UTILITIES_H
