#include "utilities.h"

#include <QFileInfo>
#include "markdown.h"

Utilities commonUtils;

Utilities::Utilities()
{

}

QString Utilities::prepareHtml(QString styles, QString input) {
    QString html = htmlTemplate;
    html.replace("<!-- styles -->", styles);
    html.replace("<!-- contents -->", Markdown().parseMarkdown(input));

    return html;
}

QString Utilities::getResource(QString path) {
    // TODO: use getFileContents method
    QFile file(path.prepend(":/"));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return "error";
    QTextStream in(&file);
    return in.readAll();
}

QString Utilities::getFileContents(QString path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return "error";
    QTextStream in(&file);
    return in.readAll();
}

QString Utilities::getFileName(QString path) {
    QFileInfo file(path);
    return file.fileName();
}
