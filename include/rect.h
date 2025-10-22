#ifndef RECT_H
#define RECT_H

#include <stdio.h>
#include "style.h"

/**
 * Struct of the rectangle and its data
 */
typedef struct
{
    int x, y;
    int width, height;
    Style *style;
} Rect;

/**
 * Function which creates a rectangle object
 */
Rect *create_rect(int x, int y, int width, int height, Style *style);

/**
 * Function to free the memory used from a rectangle
 */
void free_rect(Rect *rect);

/**
 * Function to draw the rectangle in SVG
 */
void draw_rect(FILE *f, const Rect *rect);

/**
 * Function to write down the data of a rectangle in the terminal
 */
void print_rect(const Rect *rect);

#endif
