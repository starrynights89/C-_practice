#include "Graph.h"
#include "Simple_window.h"


struct Point
{
    int x, y;
};

bool operator==(Graph_lib::Point a, Graph_lib::Point b) { return a.x==b.x && a.y==b.y; }
bool operator!=(Graph_lib::Point a, Graph_lib::Point b) { return !('a'=='b'); }

//related lines
struct Lines : Shape 
{
	Lines() {}; //empty
	Lines(initializer_list<Point>lst);

	void draw_lines() const;
	void add(Point p1, Point p2);
};

int main()
{
	//draw two lines
	const Graph_lib::Point x{ 100,100 };

	Simple_window win1{ x, 600, 400, "two lines" };

	Graph_lib::Line horizontal{ x,Graph_lib::Point{ 200,100 } }; //make a horizontal line
	Graph_lib::Line vertical{ Graph_lib::Point{ 150,50 },Graph_lib::Point{ 150,150 } };
    //make a vertical line

	win1.attach(horizontal); //attack the lines to the window
	win1.attach(vertical);

	win1.wait_for_button(); //display!
}
