#ifndef UTILITIES_H
#define UTILITIES_H

#include "ui_mainwindow.h"
#include "tabs.h"
#include "stylesheets.h"

class Utilities
{
public:
    Utilities();

    Ui::MainWindow *ui;
    QString htmlTemplate;
    QVector<Tab*> tabsList;
    Stylesheets styles;

    QString prepareHtml(QString styles, QString input);
    QString getResource(QString path);
    QString getFileContents(QString path);
    QString getFileName(QString path);

    QString openFileDialog(QString title);
    QString saveFileDialog(QString title);

    void saveFile(QString path, QString contents);

    void procedureNewTab();
    void procedureOpenFile();
    void procedureSaveFile();
    void procedureSaveAsFile();
    void procedureUndo();
    void procedureAddFileStyle();
    void procedureAddUrlStyle();
    void procedureMoveUpStyle();
    void procedureRemoveStyle();
    void procedureRefreshTextWidget();
    void procedureCloseCurrentTab();

    void setWebViewScroller();

private:
    QString parseTemplate();
};

extern Utilities commonUtils;

#endif // UTILITIES_H
