#include "style.h"
#include <string.h>

/**
 * @brief Create and initialize a Style struct dynamically
 */
Style *create_style(const char *fill, const char *stroke, int width)
{
    Style *s = malloc(sizeof(Style));
    if (!s)
        return NULL;

    strncpy(s->fill, fill, sizeof(s->fill) - 1);
    s->fill[sizeof(s->fill) - 1] = '\0';

    strncpy(s->stroke, stroke, sizeof(s->stroke) - 1);
    s->stroke[sizeof(s->stroke) - 1] = '\0';

    s->stroke_width = width;
    return s;
}

/**
 * @brief Print Style information
 */
void print_style(const Style *s)
{
    if (!s)
        return;
    printf("Style → fill: %s, stroke: %s, stroke width: %d\n",
           s->fill, s->stroke, s->stroke_width);
}

/**
 * @brief Free memory allocated to a Style
 */
void free_style(Style *s)
{
    if (s)
        free(s);
}
