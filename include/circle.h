#ifndef CIRCLE_H
#define CIRCLE_H

#include <stdio.h>
#include "style.h"

/**
 * Struct of the circle and its data
 */
typedef struct
{
    int cx, cy;
    int radius;
    Style *style;
} Circle;

/**
 * Function which creates a circle object
 */
Circle *create_circle(int cx, int cy, int radius, Style *style);

/**
 * Function to free the memory used from a circle
 */
void free_circle(Circle *c);

/**
 * Function to draw the circle in SVG
 */
void draw_circle(FILE *f, const Circle *c);

/**
 * Function to write down the data of a circle in the terminal
 */
void print_circle(const Circle *c);

#endif
