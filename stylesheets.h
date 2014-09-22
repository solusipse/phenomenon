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
    void addStylesheet(QString path, QString contents);
    void removeStylesheet(QString path);
    void addStylesheetFromFile(Ui::MainWindow *ui, QString stylesheet);
    QString getStylesheets();
    QString createStylesheetLink(QString path);
    void addStylesheetToList(Ui::MainWindow *ui, QString path);
    void updateCss();
private:
    QVector< QVector<QString> > stylesList;
    // this variable contains all stylesheets combined
    QString cssStyle;
};

#endif // STYLESHEETS_H
