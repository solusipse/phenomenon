#include "theme.h"

#include <QSplitter>

Theme::Theme(Ui::MainWindow *ui) {
    this->miscSettings(ui);
    this->createSplitter(ui);
    this->setDarkTheme();
    this->loadMainCss();
}

void Theme::miscSettings(Ui::MainWindow *ui) {
    QFont font = QFont("Ubuntu Mono", 14);

    ui->centralWidget->layout()->setContentsMargins(0,0,0,0);
    ui->plainTextEdit->setFont(font);

    QFontMetrics metrics(font);
    ui->plainTextEdit->setTabStopWidth(4 * metrics.width(' '));

    //ui->tabPanel->addTab("untitled");
    //ui->tabPanel->addTab("untitled");

    ui->tabPanel->setTabsClosable(true);
    ui->tabPanel->setMovable(true);
}

void Theme::createSplitter(Ui::MainWindow *ui) {
    QSplitter *splitter = new QSplitter(ui->customSplitter);
    QVBoxLayout *vbox = new QVBoxLayout;

    splitter->addWidget(ui->plainTextEdit);
    splitter->addWidget(ui->webView);
    vbox->addWidget(splitter);
    ui->splitterBox->setLayout(vbox);

    vbox->setContentsMargins(0,0,0,0);
    splitter->setCollapsible(0, false);
    splitter->setCollapsible(1, false);
}

void Theme::setDarkTheme() {
    qApp->setStyle(QStyleFactory::create("Fusion"));
    QPalette p = qApp->palette();
    p.setColor(QPalette::Window, QColor(53,53,53));
    p.setColor(QPalette::Button, QColor(53,53,53));
    p.setColor(QPalette::Highlight, QColor(66,66,66));
    p.setColor(QPalette::ButtonText, QColor(155,155,155));
    p.setColor(QPalette::WindowText, QColor(125,155,155));
    p.setColor(QPalette::Light, QColor(51,51,51));
    qApp->setPalette(p);
}

void Theme::loadMainCss() {
    qApp->setStyleSheet( commonUtils.getResource("misc/default.css") );
}
