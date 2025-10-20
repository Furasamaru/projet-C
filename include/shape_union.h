#ifndef SHAPE_UNION_H
#define SHAPE_UNION_H

#include <stdio.h>
#include <stdlib.h>

/*
 * ==========================
 *  SHAPE DEFINITIONS
 * ==========================
 * Structures representing each geometric shape.
 * Each will be dynamically allocated and stored in a union.
 */

typedef struct
{
    int x1, y1, x2, y2;
    char stroke[20]; // color of the line
} Line;

typedef struct
{
    int x, y, width, height;
    char fill[20];   // fill color
    char stroke[20]; // border color
} Rect;

typedef struct
{
    int cx, cy, r;
    char fill[20];
    char stroke[20];
} Circle;

typedef struct
{
    int cx, cy, rx, ry;
    char fill[20];
    char stroke[20];
} Ellipse;

/*
 * Enum defining the shape type
 */
typedef enum
{
    SHAPE_LINE,
    SHAPE_RECT,
    SHAPE_CIRCLE,
    SHAPE_ELLIPSE
} ShapeType;

/*
 * Union to store any type of shape pointer
 */
typedef union
{
    Line *line;
    Rect *rect;
    Circle *circle;
    Ellipse *ellipse;
} ShapeData;

/*
 * Main structure that binds the type with the data
 */
typedef struct
{
    ShapeType type;
    ShapeData data;
} Shape;

/*
 * Function prototypes for display and SVG export
 */
void print_shape(const Shape *s);
void export_shape_svg(FILE *f, const Shape *s);

#endif
