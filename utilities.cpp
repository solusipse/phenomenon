#include "utilities.h"

Utilities::Utilities()
{
}

QString Utilities::openCssFile(QString path) {
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return "error";

    QTextStream in(&file);
    return in.readAll();
}
