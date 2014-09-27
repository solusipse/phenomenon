#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Theme(this->ui);

    manualConnectSlots();

    commonUtils.ui = ui;
    commonUtils.htmlTemplate = commonUtils.getResource("misc/template.html");

    Tab();
    Tab();


    //ui->webView->settings()->setObjectCacheCapacities(0,0,0);
}

void MainWindow::manualConnectSlots() {
    connect(ui->tabPanel, SIGNAL(tabCloseRequested(int)), this, SLOT(deleteTab(int)));
    connect(ui->tabPanel, SIGNAL(tabBarDoubleClicked(int)), this, SLOT(addNewTab(int)));
    connect(ui->tabPanel, SIGNAL(currentChanged(int)), this, SLOT(onTabChanged(int)));
}

void MainWindow::onTabChanged(int index) {
    qDebug() << index;
}

void MainWindow::addNewTab(int index) {
    // create new tab only if user clicked on empty space
    if (index == -1) Tab();
}

void MainWindow::deleteTab (int index) {
    Tabs().close(index);
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
    QString inputText = ui->plainTextEdit->toPlainText();
    QString outputText = commonUtils.prepareHtml(styles.getStylesheets(), inputText);
    ui->webView->setHtml(outputText);
}

void MainWindow::on_cssButton_clicked()
{
    QString stylesheet = QFileDialog::getOpenFileName(this,
         tr("Open custom stylesheet"), "",
         tr("Stylesheets (*.css)"));
    if (stylesheet.isEmpty()) return;
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

void MainWindow::on_cssMoveUpButton_clicked()
{
    if (ui->stylesList->currentRow() > 0)
    {
        styles.moveStyleUp(ui);
        this->refreshTextEdit();
    }
}

void MainWindow::on_addStyleFromUrlButton_clicked()
{
    QString input = QInputDialog::getText(this,
        tr("Load Stylesheet from URL"),
        tr("URL:"), QLineEdit::Normal, "http://");
    if (input == "http://") return;
    styles.addStylesheetFromUrl(ui, input);
}
