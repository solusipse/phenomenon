#include "theme.h"

Theme::Theme(Ui::MainWindow *ui) {
    this->miscSettings(ui);
    this->setDarkTheme();
}

void Theme::miscSettings(Ui::MainWindow *ui) {
    ui->centralWidget->layout()->setContentsMargins(0,0,0,0);
    ui->plainTextEdit->setFont(QFont("Cantarell", 14));
    ui->plainTextEdit->setStyleSheet("background-color: #666; color: #DDD;");
    ui->stylesList->setStyleSheet("background-color: #333; color: #DDD;");
}

void Theme::setDarkTheme() {
    qApp->setStyle(QStyleFactory::create("Fusion"));
    QPalette p = qApp->palette();
    p.setColor(QPalette::Window, QColor(53,53,53));
    p.setColor(QPalette::Button, QColor(53,53,53));
    p.setColor(QPalette::Highlight, QColor(66,66,66));
    p.setColor(QPalette::ButtonText, QColor(155,155,155));
    p.setColor(QPalette::WindowText, QColor(125,155,155));
    qApp->setPalette(p);
}
