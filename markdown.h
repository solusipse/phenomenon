#ifndef MARKDOWN_H
#define MARKDOWN_H

#include "libs/hoedown/src/autolink.h"
#include "libs/hoedown/src/buffer.h"
#include "libs/hoedown/src/document.h"
#include "libs/hoedown/src/escape.h"
#include "libs/hoedown/src/html_blocks.c"
#include "libs/hoedown/src/html.h"
#include "libs/hoedown/src/stack.h"
#include "libs/hoedown/src/version.h"

#include <QString>

class Markdown
{
public:
    Markdown();
    QString parseMarkdown(QString input);
};


#endif // MARKDOWN_H
