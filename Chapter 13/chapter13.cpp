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

//draw two lines
constexpr Point x {100,100};

Simple_window win1 {x,600,400,"two lines"};

Line horizontal {x,Point{200,100}}; //make a horizontal line
Line vertical {Point{150,50},Point{150,150}}; //make a vertical line

win1.attach(horizontal); //attack the lines to the window
win1.attach(vertical); 

win1.wait_for_button(); //display!