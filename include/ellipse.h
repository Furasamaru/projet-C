#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <stdio.h>
#include "style.h"

/**
 * Struct of the ellipse and its data
 */
typedef struct
{
    int cx, cy;
    int r1, r2;
    Style *style;
} Ellip;

/**
 * Function which creates an ellipse object
 */
Ellip *create_ellipse(int cx, int cy, int r1, int r2, Style *style);

/**
 * Function to free the memory used from an ellipse
 */
void free_ellipse(Ellip *e);

/**
 * Function to draw the ellipse in SVG
 */
void draw_ellipse(FILE *f, const Ellip *e);

/**
 * Function to write down the data of an ellipse in the terminal
 */
void print_ellipse(const Ellip *e);

#endif