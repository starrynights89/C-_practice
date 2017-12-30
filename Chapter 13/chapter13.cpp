#include "Graph.h"
#include "Simple_window.h"
#include "Point.h"

struct Point
{
    int x, y;
}

bool operator==(Point a, Point b) { return a.x==b.x && a.y==b.y; }
bool operator!=(Point a, Point b) { return !(a==b); }