#include "stylesheets.h"

#include "tabs.h"
#include "utilities.h"

Stylesheets::Stylesheets() {
}

QString Stylesheets::createStylesheetLink(QString path) {
    QString link = "<link rel='stylesheet' type='text/css' href='";
    link.append(path);
    link.append("'>");
    return link;
}

void Stylesheets::addStylesheetFromFile(QString path) {
    new Stylesheet(path, createStylesheetLink(path.prepend("file:")));
}

void Stylesheets::addStylesheetFromUrl(QString path) {
    new Stylesheet(path, createStylesheetLink(path));
}

void Stylesheets::addToWidget(QString path) {
    commonUtils.ui->stylesList->addItem(path);
}

void Stylesheets::updateCss() {
    this->cssStyle = "";
    for(int i = 0; i < Tabs().current()->styles.size(); i++)
        this->cssStyle.append(Tabs().current()->styles[i]->link);
}

void Stylesheets::update() {
    this->updateCss();
    this->updateList();
}

QString Stylesheets::getStylesheets() {
    this->updateCss();
    return this->cssStyle;
}

void Stylesheets::removeStylesheet(QString path) {
    for(int i = 0; i < Tabs().current()->styles.size(); i++)
        if (path == Tabs().current()->styles[i]->path)
        {
            delete Tabs().current()->styles[i];
            Tabs().current()->styles.remove(i);
        }
}

void Stylesheets::moveStyleUp(QString path) {
    // TODO: fix this method
    QString buffer;
    for(int i = 0; i < Tabs().current()->styles.size(); i++)
        if (path == Tabs().current()->styles[i]->path)
        {
            buffer = Tabs().current()->styles[i-1]->path;
            Tabs().current()->styles[i-1]->path = Tabs().current()->styles[i]->path;
            Tabs().current()->styles[i]->path = buffer;
        }
    this->update();
}

void Stylesheets::updateList() {
    commonUtils.ui->stylesList->clear();
    for(int i = 0; i < Tabs().current()->styles.size(); i++)
        commonUtils.ui->stylesList->addItem(Tabs().current()->styles[i]->path);
}

// Stylesheet class

Stylesheet::Stylesheet(QString path, QString link) {
    this->path = path;
    this->link = link;
    Tabs().current()->styles.append(this);
    Stylesheets().update();
}
