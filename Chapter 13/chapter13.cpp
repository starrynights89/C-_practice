#include "Graph.h"
#include "Simple_window.h"
#include "Point.h"

struct Point
{
    int x, y;
};

bool operator==(Point a, Point b) { return a.x==b.x && a.y==b.y; }
bool operator!=(Point a, Point b) { return !(a==b); }

//a Line is a Shape defined by two Points
struct Line : Shape 
{
    Line(Point p1, Point p2) //construct a Line from two Points
};