#include "mainwindow.h"

#include <QFileDialog.h>
#include <QInputDialog.h>
#include <QLineEdit.h>

#include "ui_mainwindow.h"
#include "utilities.h"
#include "theme.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    commonUtils.ui = ui;
    commonUtils.htmlTemplate = commonUtils.getResource("misc/template.html");

    Theme();
    this->manualConnectSlots();

    // temporary, TODO: init method
    Tabs().add();
    Tabs().add();

    //ui->webView->settings()->setObjectCacheCapacities(0,0,0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* SIGNALS START HERE */

void MainWindow::manualConnectSlots() {
    connect(ui->tabPanel, SIGNAL(tabCloseRequested(int)), this, SLOT(deleteTab(int)));
    connect(ui->tabPanel, SIGNAL(tabBarDoubleClicked(int)), this, SLOT(addNewTab(int)));
    connect(ui->tabPanel, SIGNAL(currentChanged(int)), this, SLOT(onTabChanged(int)));
    // TODO: connect tabPanel with onTabMoved (not prototyped yet)
}


// TABS
void MainWindow::onTabChanged(int index) {
    ui->plainTextEdit->setPlainText(Tabs().fromIndex(index)->text);
    Stylesheets().update();
}

void MainWindow::addNewTab(int index) {
    // create new tab only if user clicked on empty space
    // TODO: switch to new tab
    if (index == -1) Tabs().add();
}

void MainWindow::deleteTab (int index) {
    Tabs().close(index);
}


// TEXT EDIT
void MainWindow::refreshTextEdit() {
    this->on_plainTextEdit_textChanged();
}

void MainWindow::on_plainTextEdit_textChanged()
{
    QString inputText = ui->plainTextEdit->toPlainText();
    Tabs().current()->text = inputText;
    QString outputText = commonUtils.prepareHtml(styles.getStylesheets(), inputText);
    ui->webView->setHtml(outputText);
}


// STYLES
void MainWindow::on_cssButton_clicked()
{
    QString stylesheet = QFileDialog::getOpenFileName(this,
         tr("Open custom stylesheet"), "",
         tr("Stylesheets (*.css)"));
    if (stylesheet.isEmpty()) return;
    styles.addStylesheetFromFile(stylesheet);
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
        QListWidgetItem *selectedItem = ui->stylesList->currentItem();
        styles.moveStyleUp(selectedItem->text());
        this->refreshTextEdit();
    }
}

void MainWindow::on_addStyleFromUrlButton_clicked()
{
    QString input = QInputDialog::getText(this,
        tr("Load Stylesheet from URL"),
        tr("URL:"), QLineEdit::Normal, "http://");
    if (input == "http://") return;
    styles.addStylesheetFromUrl(input);
}

/* Main panel buttons signals */

void MainWindow::on_panelButtonNewFile_clicked()
{
    Tabs().add();
}

/* SIGNALS END HERE */
