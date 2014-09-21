#include "stylesheets.h"

Stylesheets::Stylesheets() {

}

void Stylesheets::addStylesheet(QString path, QString contents) {
    QVector<QString> style;
    style.append(path);
    style.append(contents);
    this->stylesList.append(style);
}

void Stylesheets::addStylesheetFromFile(Ui::MainWindow *ui, QString path) {
    QString contents = Utilities().openCssFile(path);
    this->addStylesheet(path, contents);
    this->addStylesheetToList(ui, path);
}

void Stylesheets::addStylesheetToList(Ui::MainWindow *ui, QString path) {
    ui->stylesList->addItem(path);
}

void Stylesheets::updateCss() {

}
