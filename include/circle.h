#ifndef CIRCLE_H
#define CIRCLE_H

#include <stdio.h>
#include "style.h" // MUST include style.h so Circle knows what Style is

typedef struct
{
    int cx, cy;
    int radius;
    Style *style; // Pointer to a Style struct
} Circle;

// Create a new Circle
Circle *create_circle(int cx, int cy, int radius, Style *style);

// Free a Circle (does NOT free the Style)
void free_circle(Circle *c);

// Draw a Circle to a file (SVG)
void draw_circle(FILE *f, const Circle *c);

// Print a Circle to terminal
void print_circle(const Circle *c);

#endif
