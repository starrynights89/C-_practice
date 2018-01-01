#include "Graph.h"
#include "Simple_window.h"


struct Point
{
    int x, y;
};

bool operator==(Graph_lib::Point a, Graph_lib::Point b) { return a.x==b.x && a.y==b.y; }
bool operator!=(Graph_lib::Point a, Graph_lib::Point b) { return !('a'=='b'); }

//related lines
struct Line : Shape //related lines
{
	Line(Graph_lib::Point p1, Graph_lib::Point p2); 
};

int main()
{
	//draw two lines
	const Graph_lib::Point x {100,100};

	Simple_window win1{x,600, 400, "two lines" };

	Graph_lib::Line horizontal {x,Graph_lib::Point{200,100}}; 
	Graph_lib::Line vertical {Graph_lib::Point{150,50},Graph_lib::Point{150,150}};

	win1.attach(horizontal);
	win1.attach(vertical);

	win1.wait_for_button(); //display!
}
