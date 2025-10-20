#include "line.h"
#include <stdio.h>

/**
 * @brief Create a new Line dynamically.
 */
Line *create_line(int x1, int y1, int x2, int y2, Style *style)
{
    Line *line = malloc(sizeof(Line));
    if (!line)
        return NULL;

    line->x1 = x1;
    line->y1 = y1;
    line->x2 = x2;
    line->y2 = y2;
    line->style = style;

    return line;
}

/**
 * @brief Free a Line object (does NOT free the Style)
 */
void free_line(Line *line)
{
    if (!line)
        return;

    free(line);
}

/**
 * @brief Draw the Line in SVG format to a file.
 */
void draw_line(FILE *f, const Line *line)
{
    if (!f || !line || !line->style)
        return;

    fprintf(f,
            "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"%s\" stroke-width=\"%d\" />\n",
            line->x1, line->y1, line->x2, line->y2,
            line->style->stroke, line->style->stroke_width);
}

/**
 * @brief Print Line info to terminal.
 */
void print_line(const Line *line)
{
    if (!line || !line->style)
        return;

    printf("Line: (%d,%d) -> (%d,%d), stroke=%s, width=%d\n",
           line->x1, line->y1, line->x2, line->y2,
           line->style->stroke, line->style->stroke_width);
}
