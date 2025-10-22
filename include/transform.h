#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "line.h"
#include "rect.h"
#include "circle.h"
#include "ellipse.h"

/**
 * Function which changes the location of the line
 */
void move_line(Line *line, int dx, int dy);

/**
 * Function which changes the location of the rectangle
 */
void move_rect(Rect *rect, int dx, int dy);

/**
 * Function which changes the location of the circle
 */
void move_circle(Circle *circle, int dx, int dy);

/**
 * Function which changes the location of the ellipse
 */
void move_ellipse(Ellip *ellip, int dx, int dy);

/**
 * Function which changes the size of the line
 */
void rescale_line(Line *line, float factor);

/**
 * Function which changes the size of the rectangle
 */
void rescale_rect(Rect *rect, float factor);

/**
 * Function which changes the size of the circle
 */
void rescale_circle(Circle *circle, float factor);

/**
 * Function which changes the size of the ellipse
 */
void rescale_ellipse(Ellip *ellip, float factor);

/**
 * Function which changes the color of the line
 */
void recolor_line(Line *line, Style *style);

/**
 * Function which changes the color of the rectangle
 */
void recolor_rect(Rect *rect, Style *style);

/**
 * Function which changes the color of the circle
 */
void recolor_circle(Circle *circle, Style *style);

/**
 * Function which changes the color of the ellipse
 */
void recolor_ellipse(Ellip *ellip, Style *style);

#endif
