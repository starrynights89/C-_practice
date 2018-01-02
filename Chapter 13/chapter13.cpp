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
	Lines(initializer_list<Graph_lib::Point>lst); //initialize from a list of points

	void draw_lines() const;
	void add(Graph_lib::Point p1, Graph_lib::Point p2);
};

int main()
{
	using namespace Graph_lib;
	//draw two lines

	Graph_lib::Lines x;
	x.add(Graph_lib::Point{100,100},Graph_lib::Point{200,100}); //horizontal
	x.add(Graph_lib::Point{150,50},Graph_lib::Point{150,150}); //vertical\
	
}
