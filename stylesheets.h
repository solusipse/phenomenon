#ifndef STYLESHEETS_H
#define STYLESHEETS_H

#include <QString>
#include <QVector>
#include <QApplication>

#include "utilities.h"
#include "ui_mainwindow.h"


class Stylesheets
{
public:
    Stylesheets();
    void addStylesheet(QString path, QString link);
    void removeStylesheet(QString path);
    void addStylesheetFromFile(Ui::MainWindow *ui, QString path);
    void addStylesheetFromUrl(Ui::MainWindow *ui, QString path);
    void addStylesheetToList(Ui::MainWindow *ui, QString path);
    void moveStyleUp(Ui::MainWindow *ui);
    QString getStylesheets();

private:
    void updateCss();
    QString createStylesheetLink(QString path);
    QVector< QVector<QString> > stylesList;
    QString cssStyle;
    void updateList(Ui::MainWindow *ui);
};

class Stylesheet
{
public:
    Stylesheet();
    QString path;
    QString link;
};

#endif // STYLESHEETS_H
