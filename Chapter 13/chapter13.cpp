#include "Graph.h"
#include "Simple_window.h"

struct Point
{
    int x, y;
};

bool operator==(Graph_lib::Point a, Graph_lib::Point b) { return a.x==b.x && a.y==b.y; }
bool operator!=(Graph_lib::Point a, Graph_lib::Point b) { return !('a'=='b'); }

struct Lines : Shape //related lines
{
	Lines() {} //empty
	Lines(initializer_list<Point>lst); //initialize from a list of Points

	void draw_lines() const;
	void add(Point p1, Point p2); //add a line defined by two points 
};

int main()
{
	Lines x;
	x.add(Point{100,100},Point{200,100}); //horizontal
	x.add(Point{150,50},Point{150,150}); //vertical

	int x_size = win3.x_max(); //get the size of our window
	int y_size = win3.y_max();
}
