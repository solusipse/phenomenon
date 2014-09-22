#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "theme.h"
#include "utilities.h"
#include "stylesheets.h"
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        void refreshTextEdit();
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private slots:
        void on_plainTextEdit_textChanged();
        void on_cssButton_clicked();

        void on_cssRefreshButton_clicked();

private:
        Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
