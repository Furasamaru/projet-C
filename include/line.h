#ifndef LINE_H
#define LINE_H

#include <stdio.h>
#include "style.h"

typedef struct
{
    int x1, y1;
    int x2, y2;
    Style *style;
} Line;

Line *create_line(int x1, int y1, int x2, int y2, Style *style);
void free_line(Line *line);
void draw_line(FILE *f, const Line *line);
void print_line(const Line *line);

#endif
