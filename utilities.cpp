#include "utilities.h"

Utilities::Utilities()
{
    htmlTemplate = getTemplate();
}

QString Utilities::prepareHtml(QString styles, QString input) {
    QString html = this->htmlTemplate;
    html.replace("<!-- styles -->", styles);
    html.replace("<!-- contents -->", Markdown().parseMarkdown(input));

    return html;
}

QString Utilities::getTemplate() {
    const char *i = (const char *) QResource("./misc/template.html").data();
    return QString::fromUtf8(i);
}

QString Utilities::openCssFile(QString path) {
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return "error";

    QTextStream in(&file);
    return in.readAll();
}

