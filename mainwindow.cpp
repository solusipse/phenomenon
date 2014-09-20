#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->layout()->setContentsMargins(0,0,0,0);

    ui->plainTextEdit->setFont(QFont("Cantarell", 14));
    ui->plainTextEdit->setStyleSheet("background-color: #666; color: #DDD;");
    ui->stylesList->setStyleSheet("background-color: #333; color: #DDD;");

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

void MainWindow::on_cssButton_clicked()
{
    QString stylesheet = QFileDialog::getOpenFileName(this,
         tr("Open custom stylesheet"), "", tr("Stylesheets (*.css)"));

    QString contents = Utilities().openCssFile(stylesheet);

    ui->stylesList->addItem(stylesheet);


}
