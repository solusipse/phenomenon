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

    ui->statusBar->showMessage("Ready", 5000);

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
    if (index == -1) commonUtils.procedureNewTab();
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
    commonUtils.procedureRefreshTextWidget();
}


/* Stylesheets buttons signals */
void MainWindow::on_cssButton_clicked()
{
    commonUtils.procedureAddFileStyle();
}

void MainWindow::on_removeStylesheetButton_clicked()
{
    commonUtils.procedureRemoveStyle();
}

void MainWindow::on_cssMoveUpButton_clicked()
{
    commonUtils.procedureMoveUpStyle();
}

void MainWindow::on_addStyleFromUrlButton_clicked()
{
    commonUtils.procedureAddUrlStyle();
}

/* Main panel buttons signals */

void MainWindow::on_panelButtonNewFile_clicked() {
    commonUtils.procedureNewTab();
}

void MainWindow::on_panelButtonOpenFile_clicked() {
    commonUtils.procedureOpenFile();
}

void MainWindow::on_panelButtonSave_clicked() {
    commonUtils.procedureSaveFile();
}

void MainWindow::on_panelButtonSaveAs_clicked() {
    commonUtils.procedureSaveAsFile();
}

void MainWindow::on_panelButtonCut_clicked() {
    commonUtils.ui->plainTextEdit->cut();
}

void MainWindow::on_panelButtonCopy_clicked() {
    commonUtils.ui->plainTextEdit->copy();
}

void MainWindow::on_panelButtonPaste_clicked() {
    commonUtils.ui->plainTextEdit->paste();
}

void MainWindow::on_panelButtonUndo_clicked() {
    commonUtils.procedureUndo();
}
