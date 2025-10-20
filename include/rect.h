#ifndef RECT_H
#define RECT_H

#include <stdio.h>
#include "style.h"

typedef struct
{
    int x, y;
    int width, height;
    Style *style;
} Rect;

Rect *create_rect(int x, int y, int width, int height, Style *style);
void free_rect(Rect *rect);
void draw_rect(FILE *f, const Rect *rect);
void print_rect(const Rect *rect);

#endif
