#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QInputDialog>

#include "theme.h"
#include "utilities.h"
#include "stylesheets.h"
#include "ui_mainwindow.h"
#include "markdown.h"

extern "C" {

}

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

        void on_removeStylesheetButton_clicked();


        void on_cssMoveUpButton_clicked();

        void on_addStyleFromUrlButton_clicked();

private:
        Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
