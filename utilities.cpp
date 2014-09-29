#include "utilities.h"

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
    QFile file(path.prepend(":/"));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return "error";
    QTextStream in(&file);
    return in.readAll();
}

