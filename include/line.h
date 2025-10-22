#ifndef LINE_H
#define LINE_H

#include <stdio.h>
#include "style.h"

/**
 * Struct of the line and its data
 */
typedef struct
{
    int x1, y1;
    int x2, y2;
    Style *style;
} Line;

/**
 * Function which creates a line object
 */
Line *create_line(int x1, int y1, int x2, int y2, Style *style);

/**
 * Function to free the memory used from a line
 */
void free_line(Line *line);

/**
 * Function to draw the line in SVG
 */
void draw_line(FILE *f, const Line *line);

/**
 * Function to write down the data of a line in the terminal
 */
void print_line(const Line *line);

#endif