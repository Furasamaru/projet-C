#include "circle.h"
#include <stdlib.h>
#include <stdio.h>

Circle *create_circle(int cx, int cy, int radius, Style *style)
{
    Circle *c = malloc(sizeof(Circle));
    if (!c)
        return NULL;
    c->cx = cx;
    c->cy = cy;
    c->radius = radius;
    c->style = style;
    return c;
}

void free_circle(Circle *c)
{
    if (c)
        free(c);
}

void draw_circle(FILE *f, const Circle *c)
{
    if (!f || !c || !c->style)
        return;
    fprintf(f, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%d\" />\n",
            c->cx, c->cy, c->radius,
            c->style->fill, c->style->stroke, c->style->stroke_width);
}

void print_circle(const Circle *c)
{
    if (!c || !c->style)
        return;
    printf("Circle: center=(%d,%d), radius=%d, fill=%s, stroke=%s, width=%d\n",
           c->cx, c->cy, c->radius,
           c->style->fill, c->style->stroke, c->style->stroke_width);
}
