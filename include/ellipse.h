#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <stdio.h>
#include "style.h"

typedef struct
{
    int cx, cy;
    int r1, r2;
    Style *style;
} Ellip;

Ellip *create_ellipse(int cx, int cy, int r1, int r2, Style *style);
void free_ellipse(Ellip *e);
void draw_ellipse(FILE *f, const Ellip *e);
void print_ellipse(const Ellip *e);

#endif