#include "mainwindow.h"
#include "ui_mainwindow.h"


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

void MainWindow::on_plainTextEdit_textChanged()
{
    /* Now it's simple html-only rendering method. */
    QString inputText = ui->plainTextEdit->toPlainText();
    ui->webView->setHtml(inputText);
}

void MainWindow::on_cssButton_clicked()
{
    QString stylesheet = QFileDialog::getOpenFileName(this,
         tr("Open custom stylesheet"), "", tr("Stylesheets (*.css)"));
    Stylesheets().addStylesheetFromFile(this->ui, stylesheet);
}
