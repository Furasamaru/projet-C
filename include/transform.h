#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "line.h"
#include "rect.h"
#include "circle.h"
#include "ellipse.h"

// Déplace une forme

void move_line(Line *line, int dx, int dy);
void move_rect(Rect *rect, int dx, int dy);
void move_circle(Circle *circle, int dx, int dy);
void move_ellipse(Ellip *ellip, int dx, int dy);

// Agrandit ou réduit une forme

void rescale_line(Line *line, float factor);
void rescale_rect(Rect *rect, float factor);
void rescale_circle(Circle *circle, float factor);
void rescale_ellipse(Ellip *ellip, float factor);

// change les couleurs

void recolor_line(Line *line, Style *style);
void recolor_rect(Rect *rect, Style *style);
void recolor_circle(Circle *circle, Style *style);
void recolor_ellipse(Ellip *ellip, Style *style);

#endif
