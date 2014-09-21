#ifndef STYLESHEETS_H
#define STYLESHEETS_H

#include <QFileDialog>
#include <QString>
#include <QVector>
#include <QApplication>

#include "utilities.h"


class Stylesheets
{
public:
    Stylesheets();
    void addStylesheet(QString path, QString contents);
    void removeStylesheet(int id);
    void addStylesheetFromFile(Ui::MainWindow *ui, QString stylesheet);
    QString getStylesheets();
    void addStylesheetToList(Ui::MainWindow *ui, QString path);
private:
    QVector< QVector<QString> > stylesList;
    // this variable contains all stylesheets combined
    QString cssStyle;
    void updateCss();
};

#endif // STYLESHEETS_H
