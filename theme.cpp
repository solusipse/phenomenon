#include "theme.h"

Theme::Theme(Ui::MainWindow *ui) {
    this->miscSettings(ui);
    this->setDarkTheme();
    this->loadMainCss();
}

void Theme::miscSettings(Ui::MainWindow *ui) {
    QFont font = QFont("Ubuntu Mono", 14);

    ui->centralWidget->layout()->setContentsMargins(0,0,0,0);
    ui->plainTextEdit->setFont(font);

    QFontMetrics metrics(font);
    ui->plainTextEdit->setTabStopWidth(4 * metrics.width(' '));

    ui->tabPanel->addTab("untitled");
    ui->tabPanel->addTab("untitled");

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
    qApp->setStyleSheet( Utilities().getResource("misc/default.css") );
}
