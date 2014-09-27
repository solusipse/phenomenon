#ifndef THEME_H
#define THEME_H

#include <QStyleFactory>
#include <QApplication>
#include <QResource>
#include <QSplitter>
#include <QPushButton>
#include "utilities.h"
#include "ui_mainwindow.h"

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
