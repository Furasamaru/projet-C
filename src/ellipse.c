#include "../include/ellipse.h"
#include <stdlib.h>
#include <stdio.h>

Ellip *create_ellipse(int cx, int cy, int r1, int r2, Style *style)
{
    Ellip *e = malloc(sizeof(Ellip));
    if (!e)
        return NULL;
    e->cx = cx;
    e->cy = cy;
    e->r1 = r1;
    e->r2 = r2;
    e->style = style;
    return e;
}

void free_ellipse(Ellip *e)
{
    if (e)
        free(e);
}

void draw_ellipse(FILE *f, const Ellip *e)
{
    if (!f || !e || !e->style)
        return;
    fprintf(f, "<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%d\" />\n",
            e->cx, e->cy, e->r1, e->r2,
            e->style->fill, e->style->stroke, e->style->stroke_width);
}

void print_ellipse(const Ellip *e)
{
    if (!e || !e->style)
        return;
    printf("Ellipse: center=(%d,%d), rx=%d, ry=%d, fill=%s, stroke=%s, width=%d\n",
           e->cx, e->cy, e->r1, e->r2,
           e->style->fill, e->style->stroke, e->style->stroke_width);
}
