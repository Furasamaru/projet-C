#include <stdio.h>
#include "transform.h"

// déplace une forme

void move_line(Line *line, int dx, int dy)
{
    if (!line)
        return;
    line->x1 += dx;
    line->y1 += dy;
    line->x2 += dx;
    line->y2 += dy;
}

void move_rect(Rect *rect, int dx, int dy)
{
    if (!rect)
        return;
    rect->x += dx;
    rect->y += dy;
}

void move_circle(Circle *circle, int dx, int dy)
{
    if (!circle)
        return;
    circle->cx += dx;
    circle->cy += dy;
}

void move_ellipse(Ellip *ellipse, int dx, int dy)
{
    if (!ellipse)
        return;
    ellipse->cx += dx;
    ellipse->cy += dy;
}

// agrandi ou réduit une forme

void rescale_line(Line *line, float factor)
{
    if (!line)
        return;
    line->x1 *= factor;
    line->y1 *= factor;
    line->x2 *= factor;
    line->y2 *= factor;
}

void rescale_rect(Rect *rect, float factor)
{
    if (!rect)
        return;
    rect->width *= factor;
    rect->height *= factor;
    rect->x *= factor;
    rect->y *= factor;
}

void rescale_circle(Circle *circle, float factor)
{
    if (!circle)
        return;
    circle->radius *= factor;
    circle->cx *= factor;
    circle->cy *= factor;
}

void rescale_ellipse(Ellip *ellipse, float factor)
{
    if (!ellipse)
        return;
    ellipse->r1 *= factor;
    ellipse->r2 *= factor;
    ellipse->cx *= factor;
    ellipse->cy *= factor;
}

// change les couleurs

void recolor_line(Line *line, Style *style)
{
    if (!style)
        return;
    line->style = style;
}

void recolor_rect(Rect *rect, Style *style)
{
    if (!style)
        return;
    rect->style = style;
}

void recolor_circle(Circle *circle, Style *style)
{
    if (!style)
        return;
    circle->style = style;
}

void recolor_ellipse(Ellip *ellip, Style *style)
{
    if (!style)
        return;
    ellip->style = style;
}
