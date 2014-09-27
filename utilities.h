#ifndef UTILITIES_H
#define UTILITIES_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QResource>

#include "stylesheets.h"
#include "markdown.h"

class Utilities
{
public:
    Utilities();
    QString prepareHtml(QString styles, QString input);
    QString getResource(QString path);
    QString htmlTemplate;
private:
    QString parseTemplate();
};

#endif // UTILITIES_H
