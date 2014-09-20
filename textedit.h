#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QPlainTextEdit>

class TextEdit : public QPlainTextEdit
{
    Q_OBJECT
    public:
        explicit TextEdit(QPlainTextEdit *parent = 0);

    signals:

    public slots:

    private slots:

};

#endif // TEXTEDIT_H
