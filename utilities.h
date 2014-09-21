#ifndef UTILITIES_H
#define UTILITIES_H

#include <QString>
#include <QFile>
#include <QTextStream>

#include "mainwindow.h"

class Utilities
{
public:
    Utilities();
    QString openCssFile(QString path);
};

#endif // UTILITIES_H
