#include "theme.h"

Theme::Theme()
{
    this->setDarkTheme();
}

void Theme::setDarkTheme()
{
    qApp->setStyle(QStyleFactory::create("Fusion"));
    QPalette p = qApp->palette();
    p.setColor(QPalette::Window, QColor(53,53,53));
    p.setColor(QPalette::Button, QColor(53,53,53));
    p.setColor(QPalette::Highlight, QColor(66,66,66));
    p.setColor(QPalette::ButtonText, QColor(155,155,155));
    p.setColor(QPalette::WindowText, QColor(125,155,155));
    qApp->setPalette(p);
}
