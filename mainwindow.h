#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow.h>
#include "stylesheets.h"

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
        void deleteTab(int index);
        void addNewTab(int index);
        void onTabChanged(int index);
        void on_panelButtonNewFile_clicked();
        void on_panelButtonOpenFile_clicked();
        void on_panelButtonSave_clicked();
        void on_panelButtonSaveAs_clicked();
        void on_panelButtonCut_clicked();
        void on_panelButtonCopy_clicked();
        void on_panelButtonPaste_clicked();
        void on_panelButtonUndo_clicked();

private:
        Ui::MainWindow *ui;
        void manualConnectSlots();
};

#endif // MAINWINDOW_H
