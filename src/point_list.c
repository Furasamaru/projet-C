#include <stdlib.h>
#include <point_list.h>

void add_point(PointList *list, int x, int y)
{
        Point *new = malloc(sizeof(Point));
        if (!new)
                return;
        new->x = x;
        new->y = y;
        new->next = NULL;

        if (list->head == NULL)
        {
                list->head = new;
                list->tail = new;
        }
        else
        {
                list->tail->next = new;
                list->tail = new;
        }
}