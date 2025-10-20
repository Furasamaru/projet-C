#include "rect.h"
#include <stdlib.h>

Rect *create_rect(int x, int y, int width, int height, Style *style)
{
    Rect *r = malloc(sizeof(Rect));
    if (!r)
        return NULL;
    r->x = x;
    r->y = y;
    r->width = width;
    r->height = height;
    r->style = style;
    return r;
}

void free_rect(Rect *rect)
{
    if (rect)
        free(rect);
}

void draw_rect(FILE *f, const Rect *rect)
{
    if (!f || !rect || !rect->style)
        return;
    fprintf(f, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%d\" />\n",
            rect->x, rect->y, rect->width, rect->height,
            rect->style->fill, rect->style->stroke, rect->style->stroke_width);
}

void print_rect(const Rect *rect)
{
    if (!rect || !rect->style)
        return;
    printf("Rect: (%d,%d) size=(%d,%d), fill=%s, stroke=%s, width=%d\n",
           rect->x, rect->y, rect->width, rect->height,
           rect->style->fill, rect->style->stroke, rect->style->stroke_width);
}
