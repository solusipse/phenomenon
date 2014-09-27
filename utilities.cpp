#include "utilities.h"

Utilities::Utilities()
{
    htmlTemplate = getResource("misc/template.html");
}

QString Utilities::prepareHtml(QString styles, QString input) {
    QString html = this->htmlTemplate;
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
