#ifndef point_h
#define point_h

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct point
{
    int x;
    int y;
    int z;
} Point;

/**
 * @brief Calcule de la distance entre 2 points.
 * Complexité en temps : O(1).
 * Complexité en mémoire : O(1).
 *
 * @param p1    Premier point.
 * @param p2    Deuxième point.
 * @return      Un double reprensetant la distance entre deux points.
 */
double dist(Point p1, Point p2);

/**
 * @brief Calcule de la distance entre l'origine et un point.
 * Complexité en temps : O(1).
 * Complexité en mémoire : O(1).
 *
 * @param point    Point.
 * @return         Un double reprensetant la distance entre l'origine et le point.
 */
double distOrigine(Point point);

#endif
