#ifndef POINT_LIST_H
#define POINT_LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
       int x;
       int y;
       struct Point *next;
} Point;

typedef struct
{
       Point *head;
       Point *tail;
       int count;
} PointList;

void add_point(PointList *list, int x, int y);

#endif