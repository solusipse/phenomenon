#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "theme.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->layout()->setContentsMargins(0,0,0,0);

    ui->plainTextEdit->setFont(QFont("Cantarell", 14));
    ui->plainTextEdit->setStyleSheet("background-color: #666; color: #DDD;");

    Theme();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_plainTextEdit_textChanged()
{
    QString inputText = ui->plainTextEdit->toPlainText();
    ui->webView->setHtml(inputText);
}
