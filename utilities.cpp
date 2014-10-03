#include "utilities.h"

#include <QFileInfo>
#include <QFileDialog>
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
    return getFileContents(path.prepend(":/"));
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

void Utilities::saveFile(QString path, QString contents) {
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    out << contents;
    file.close();

    // TODO: add statusbar tooltips
}

QString Utilities::openFileDialog(QString title) {
    return QFileDialog::getOpenFileName(ui->centralWidget, title);
}

QString Utilities::saveFileDialog(QString title) {
    return QFileDialog::getSaveFileName(ui->centralWidget, title);
}

void Utilities::procedureNewTab() {
    Tabs().add();
}

void Utilities::procedureOpenFile() {
    QString filePath = commonUtils.openFileDialog("Open");
    if (filePath.isEmpty()) return;

    new Tab(commonUtils.getFileName(filePath), commonUtils.getFileContents(filePath), filePath);
}

void Utilities::procedureSaveFile() {
    if (Tabs().current()->path.isEmpty()) {
        procedureSaveAsFile();
    }
    else {
        commonUtils.saveFile(Tabs().current()->path, Tabs().current()->text);
        Tabs().current()->update();
    }
}

void Utilities::procedureSaveAsFile() {
    QString filePath = commonUtils.saveFileDialog("Save");
    if (filePath.isEmpty()) return;
    Tabs().current()->path = filePath;

    procedureSaveFile();
}

void Utilities::procedureUndo() {
    ui->plainTextEdit->undo();
}

void Utilities::procedureAddFileStyle() {
    // TODO
}
