#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

#include "theme.h"
#include "utilities.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

private slots:
    void on_plainTextEdit_textChanged();

    void on_cssButton_clicked();

private:
        Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
