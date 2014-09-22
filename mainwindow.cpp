#include "mainwindow.h"
#include "ui_mainwindow.h"

Stylesheets styles = Stylesheets();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Theme(this->ui);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshTextEdit() {
    this->on_plainTextEdit_textChanged();
}

void MainWindow::on_plainTextEdit_textChanged()
{
    /* Now it's simple html-only rendering method. */
    QString inputText = ui->plainTextEdit->toPlainText();
    QString outputText = styles.getStylesheets();
    outputText.append(inputText);
    ui->webView->setHtml(outputText);
}

void MainWindow::on_cssButton_clicked()
{
    QString stylesheet = QFileDialog::getOpenFileName(this,
         tr("Open custom stylesheet"), "",
         tr("Stylesheets (*.css)"));
    styles.addStylesheetFromFile(this->ui, stylesheet);
    this->refreshTextEdit();
}

void MainWindow::on_removeStylesheetButton_clicked()
{
    if (!ui->stylesList->selectedItems().empty())
    {
        QListWidgetItem *selectedItem = ui->stylesList->currentItem();
        styles.removeStylesheet(selectedItem->text());
        delete selectedItem;
        this->refreshTextEdit();
    }
}
