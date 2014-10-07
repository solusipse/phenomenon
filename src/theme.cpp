#include "theme.h"

#include <QSplitter>
#include <QStyleFactory.h>

#include "utilities.h"

Theme::Theme() {
    this->miscSettings();
    this->createSplitter();
    this->setDarkTheme();
    this->loadMainCss();
}

void Theme::miscSettings() {
    QFont font = QFont("Ubuntu Mono", 14);

    commonUtils.ui->centralWidget->layout()->setContentsMargins(0,0,0,0);
    commonUtils.ui->plainTextEdit->setFont(font);

    QFontMetrics metrics(font);
    commonUtils.ui->plainTextEdit->setTabStopWidth(4 * metrics.width(' '));

    commonUtils.ui->tabPanel->setTabsClosable(true);
    commonUtils.ui->tabPanel->setMovable(true);
    commonUtils.ui->tabPanel->setExpanding(false);
}

void Theme::createSplitter() {
    QSplitter *splitter = new QSplitter(commonUtils.ui->customSplitter);
    QVBoxLayout *vbox = new QVBoxLayout;

    splitter->addWidget(commonUtils.ui->plainTextEdit);
    splitter->addWidget(commonUtils.ui->webView);
    vbox->addWidget(splitter);
    commonUtils.ui->splitterBox->setLayout(vbox);

    splitter->setStretchFactor(0, 3);
    splitter->setStretchFactor(1, 1);

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
