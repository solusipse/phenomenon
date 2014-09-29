#ifndef THEME_H
#define THEME_H

#include <QStyleFactory.h>

#include "ui_mainwindow.h"
#include "utilities.h"

class Theme
{
    public:
        Theme(Ui::MainWindow *ui);
    private:
        void setDarkTheme();
        void miscSettings(Ui::MainWindow *ui);
        void loadMainCss();
        void createSplitter(Ui::MainWindow *ui);
};

#endif // THEME_H
