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
	Lines(initializer_list<Graph_lib::Point>lst); //initialize from a list of Points

	void draw_lines() const;
	void add(Graph_lib::Point p1, Graph_lib::Point p2); //add a line defined by two points 
};

int main()
{
	Simple_window win(Graph_lib::Point(100, 100), 600, 400, "Canvas"); //make a window

	Graph_lib::Lines x;
	x.add(Graph_lib::Point{ 100,100 }, Graph_lib::Point{ 200,100 }); //horizontal line 
	x.add(Graph_lib::Point{ 150,50 }, Graph_lib::Point{ 150,150 }); //vertical line

	int x_size = win.x_max(); //get the size of our window
	int y_size = win.y_max();
	int x_grid = 80;
	int y_grid = 40;

	Graph_lib::Lines grid;
	for(int x=x_grid; x<x_size; x+=x_grid)
	{
		grid.add(Graph_lib::Point{x,0},Graph_lib::Point{x,y_size}); //vertical line
	}
	for(int y=y_grid; y<y_size; y+=y_grid)
	{
		grid.add(Graph_lib::Point{0,y},Graph_lib::Point{x_size,y}); //horizontal line
	}

	grid.set_color(Color::red);
	grid.set_style(Line_style{Line_style::dash,2});

	//win.attach(x);
	win.attach(grid);
	win.wait_for_button();
}
