#include "utilities.h"

#include <QFileInfo>
#include <QFileDialog>
#include <QInputDialog>
#include <QWebFrame>
#include <QScrollBar>

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
    // TODO: make tab-oriented mechanism
    ui->plainTextEdit->undo();
}

void Utilities::procedureRedo() {
    // TODO: make tab-oriented mechanism
    ui->plainTextEdit->redo();
}

void Utilities::procedureCut() {
    commonUtils.ui->plainTextEdit->cut();
}

void Utilities::procedureCopy() {
    commonUtils.ui->plainTextEdit->copy();
}

void Utilities::procedurePaste() {
    commonUtils.ui->plainTextEdit->paste();
}

void Utilities::procedureAddFileStyle() {
    QString stylesheet = openFileDialog("Add stylesheet from file");
    if (stylesheet.isEmpty()) return;
    styles.addStylesheetFromFile(stylesheet);
    procedureRefreshTextWidget();
}

void Utilities::procedureAddUrlStyle() {
    QString input = QInputDialog::getText(
        ui->centralWidget, "Load Stylesheet from URL", "URL:", QLineEdit::Normal, "http://");
    if (input == "http://" || input.isEmpty()) return;
    styles.addStylesheetFromUrl(input);
}

void Utilities::procedureRemoveStyle() {
    if (!ui->stylesList->selectedItems().empty())
    {
        QListWidgetItem *selectedItem = ui->stylesList->currentItem();
        styles.removeStylesheet(selectedItem->text());
        delete selectedItem;
        procedureRefreshTextWidget();
    }
}

void Utilities::procedureMoveUpStyle() {
    if (ui->stylesList->currentRow() > 0)
    {
        QListWidgetItem *selectedItem = ui->stylesList->currentItem();
        styles.moveStyleUp(selectedItem->text());
        procedureRefreshTextWidget();
    }
}

void Utilities::setWebViewScroller() {
    float currentScroll = (float) Tabs().current()->scrollPosition;
    float maxScroll = (float) Tabs().current()->maxScrollPosition;
    float textWidgetScrollPosition = (float) ui->plainTextEdit->verticalScrollBar()->sliderPosition();
    float textWidgetScrollMaxPosition = (float) ui->plainTextEdit->verticalScrollBar()->maximum();
    float scrollPercentage = currentScroll / maxScroll;
    float textWidgetScrollPercentage = textWidgetScrollPosition / textWidgetScrollMaxPosition;

    if (textWidgetScrollPercentage > 0.9)
        ui->webView->page()->currentFrame()->setScrollPosition(QPoint(0, maxScroll));
    if (currentScroll == 0 || maxScroll == 0)
        return;
    if (scrollPercentage > 0.8)
        ui->webView->page()->currentFrame()->setScrollPosition(QPoint(0, maxScroll));
    else
        ui->webView->page()->currentFrame()->setScrollPosition(QPoint(0, currentScroll));
}

void Utilities::procedureRefreshTextWidget() {
    // scrolling
    Tabs().current()->scrollPosition = ui->webView->page()->currentFrame()->scrollPosition().y();
    Tabs().current()->maxScrollPosition = ui->webView->page()->currentFrame()->scrollBarMaximum(Qt::Orientation(0));

    // text rendering
    QString inputText = ui->plainTextEdit->toPlainText();
    Tabs().current()->text = inputText;
    QString outputText = prepareHtml(commonUtils.styles.getStylesheets(), inputText);
    ui->webView->setHtml(outputText);
}

void Utilities::procedureCloseCurrentTab() {
    Tabs().current()->close();
}

void Utilities::procedureCloseAllTabs() {
    int i = Tabs().count() - 1;
    for (int j = 0; i > j; i--)
        Tabs().close(i);
    Tabs().current()->close();
}
