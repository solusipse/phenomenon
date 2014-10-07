#include "markdown.h"

#include "libs/hoedown/src/autolink.h"
#include "libs/hoedown/src/buffer.h"
#include "libs/hoedown/src/document.h"
#include "libs/hoedown/src/escape.h"
#include "libs/hoedown/src/html_blocks.c"
#include "libs/hoedown/src/html.h"
#include "libs/hoedown/src/stack.h"
#include "libs/hoedown/src/version.h"

Markdown::Markdown()
{
}

#define DEF_IUNIT 1024
#define DEF_OUNIT 64
#define DEF_MAX_NESTING 16

QString Markdown::parseMarkdown(QString input) {

    if (input == "") input.append(" ");

    hoedown_buffer *ib, *ob;
    size_t iunit = DEF_IUNIT, ounit = DEF_OUNIT;
    hoedown_document *document;
    hoedown_extensions extensions;
    size_t max_nesting = DEF_MAX_NESTING;
    hoedown_renderer *renderer = NULL;
    void (*renderer_free)(hoedown_renderer*) = NULL;
    hoedown_html_flags html_flags;
    int toc_level = 0;

    html_flags = HOEDOWN_HTML_HARD_WRAP;
    extensions = HOEDOWN_EXT_QUOTE;

    renderer = hoedown_html_renderer_new(html_flags, toc_level);
    renderer_free = hoedown_html_renderer_free;

    ib = hoedown_buffer_new(iunit);

    // reading input

        std::string stdStringInput = input.toUtf8().constData();
        unsigned char* charInput = (unsigned char *)stdStringInput.c_str();

        ib->data = charInput + ib->size;
        ib->size = strlen((char*)charInput);

    // eori

    ob = hoedown_buffer_new(ounit);
    document = hoedown_document_new(renderer, extensions, max_nesting);
    hoedown_document_render(document, ob, ib->data, ib->size);

    std::string outputStdString = (char*) ob->data;

    // this is for trimming output buffer
    outputStdString.erase(ob->size, outputStdString.length());

    hoedown_document_free(document);
    hoedown_buffer_free(ob);
    renderer_free(renderer);
    free(ib);

    QString output = QString::fromStdString(outputStdString);
    return output;
}
