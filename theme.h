#ifndef THEME_H
#define THEME_H

#include <QStyleFactory>
#include <QMainWindow>
#include <QApplication>
#include "ui_mainwindow.h"

class Theme
{
    public:
        Theme(Ui::MainWindow *ui);
    private:
        void setDarkTheme();
        void miscSettings(Ui::MainWindow *ui);

};

#endif // THEME_H
