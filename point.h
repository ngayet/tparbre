#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifndef point_h
#define point_h

typedef struct point{
    int x;
    int y;
    int z;
}Point;

Point creerPoint(int x, int y, int z);
double dist(Point p1, Point p2);
double distOrigine(Point point);

#endif
