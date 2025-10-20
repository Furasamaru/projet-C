#ifndef STYLE_H
#define STYLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char fill[32];
    char stroke[32];
    int stroke_width;
} Style;

// Create a new Style
Style *create_style(const char *fill, const char *stroke, int stroke_width);

// Free a Style
void free_style(Style *s);

// Print Style to terminal
void print_style(const Style *s);

#endif
