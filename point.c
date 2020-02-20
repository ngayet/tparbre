#include "point.h"

double dist(Point p1, Point p2)
{

    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2) + pow((p1.z - p2.z), 2));
}

double distOrigine(Point point)
{

    return sqrt(pow((point.x), 2) + pow((point.y), 2) + pow((point.z), 2));
}
