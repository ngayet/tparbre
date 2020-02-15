#ifndef point_h
#define point_h

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct point{
    int x;
    int y;
    int z;
}Point;

#define EGAL 0
#define DISTANCE_EGAL_COORDONNEES_NON_EGAL 1
#define POINT_1_PLUS_GRAND 2
#define POINT_1_PLUS_PETIT 3

double dist(Point p1, Point p2);
double distOrigine(Point point);
int egal(Point point_1, Point point_2);

#endif
