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
    QString openCssFile(QString path);
    QString prepareHtml(QString styles, QString input);
    QString htmlTemplate;
private:
    QString parseTemplate();
    QString getTemplate();
};

#endif // UTILITIES_H
