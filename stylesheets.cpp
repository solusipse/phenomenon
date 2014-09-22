#include "stylesheets.h"

Stylesheets::Stylesheets() {
}

void Stylesheets::addStylesheet(QString path, QString contents) {
    QVector<QString> style;
    style.append(path);
    style.append(contents);
    this->stylesList.append(style);
    this->updateCss();
}

QString Stylesheets::createStylesheetLink(QString path) {
    QString link = "<link rel='stylesheet' type='text/css' href='";
    link.append(path);
    link.append("'>");
    return link;
}

void Stylesheets::addStylesheetFromFile(Ui::MainWindow *ui, QString path) {
    QString link = this->createStylesheetLink(path.prepend("file:"));
    this->addStylesheet(path, link);
    this->addStylesheetToList(ui, path);
}

void Stylesheets::addStylesheetToList(Ui::MainWindow *ui, QString path) {
    ui->stylesList->addItem(path);
}

void Stylesheets::updateCss() {
    cssStyle = "";
    for(int i = 0; i < stylesList.size(); i++)
        this->cssStyle.append(stylesList[i][1]);
}

QString Stylesheets::getStylesheets() {
    return this->cssStyle;
}

void Stylesheets::removeStylesheet(QString path) {
    for(int i = 0; i < stylesList.size(); i++)
        if (path == stylesList[i][0])
            stylesList.remove(i);
    this->updateCss();
}
