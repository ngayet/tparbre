#include "point.h"

// int main(int argc, char const *argv[]) {
//
//     Point p1 = creerPoint(5,10,55);
//     Point p2 = creerPoint(5,10,50);
//
//     int a = dist(p1,p2);
//     printf("Distance entre 2 points : %d\n", a);
//
//     return 0;
// }

int egal(Point point_1, Point point_2)
{
    if (dist(point_1, point_2) == 0)
    {
        return EGAL;
    }
    else if (distOrigine(point_1) == distOrigine(point_2))
    {
        return DISTANCE_EGAL_COORDONNEES_NON_EGAL;
    }
    else if (distOrigine(point_1) > distOrigine(point_2))
    {
        return POINT_1_PLUS_GRAND;
    }
    else
    {
        return POINT_1_PLUS_PETIT;
    }
}

/**
 * Calcule de la distance entre 2 points.
 * Complexité en temps : O(1).
 * Complexité en mémoire : O(1).
 *
 * @param p1    Premier point.
 * @param p2    Deuxième point.
 * @return      Un double reprensetant la distance entre deux points.
 */
double dist(Point p1, Point p2)
{

    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2) + pow((p1.z - p2.z), 2));
}

/**
 * Calcule de la distance entre l'origine et un point.
 * Complexité en temps : O(1).
 * Complexité en mémoire : O(1).
 *
 * @param point    Point.
 * @return         Un double reprensetant la distance entre l'origine et le point.
 */
double distOrigine(Point point)
{

    return sqrt(pow((point.x), 2) + pow((point.y), 2) + pow((point.z), 2));
}
