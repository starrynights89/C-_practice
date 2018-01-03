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

//rectangle class
struct Rectangle : Shape
{
	Rectangle(Graph_lib::Point xy, int ww, int hh);
	Rectangle(Graph_lib::Point x, Graph_lib::Point y);
	void draw_lines() const;

	int height() const { return h; }
	int width() const { return w; }
private:
	int h; //height 
	int w; //width
};
//rectangle constructor
Graph_lib::Rectangle::Rectangle(Point xy, int ww, int hh)
	:w{ww}, h{hh}
{
	if (h<=0 || w<=0)
	{
		error("Bad rectangle: non-positivbe side");
	}
	add(xy);
}
//rectangle constructor
Graph_lib::Rectangle::Rectangle(Point x, Point y)
	:w{y.x-x.x},h{y.y-x.y}
{
	if(h<=0 || w<=0)
	{
		error("Bade rectangle: first point is not top left");
	}
	add(x);
}

int main()
{
	Simple_window win(Graph_lib::Point(100, 100), 600, 400, "Canvas"); //make a window

	//lines
	Graph_lib::Lines x;
	x.add(Graph_lib::Point{ 100,100 }, Graph_lib::Point{ 200,100 }); //horizontal line 
	x.add(Graph_lib::Point{ 150,50 }, Graph_lib::Point{ 150,150 }); //vertical line

	int x_size = win.x_max(); //get the size of our window
	int y_size = win.y_max();
	int x_grid = 80;
	int y_grid = 40;

	//grid
	Graph_lib::Lines grid;
	for(int x=x_grid; x<x_size; x+=x_grid)
	{
		grid.add(Graph_lib::Point{x,0},Graph_lib::Point{x,y_size}); //vertical line
	}
	for(int y=y_grid; y<y_size; y+=y_grid)
	{
		grid.add(Graph_lib::Point{0,y},Graph_lib::Point{x_size,y}); //horizontal line
	}
	//grid color
	grid.set_color(Color::red);
	grid.set_style(Line_style{Line_style::dash,2});
	//open polyline
	Open_polyline opl;
	opl.add(Graph_lib::Point(100,100));
	opl.add(Graph_lib::Point(150,200));
	opl.add(Graph_lib::Point(250,250));
	opl.add(Graph_lib::Point(300,200));
	//close polyline
	Closed_polyline cpl;
	cpl.add(Graph_lib::Point(100,100));
	cpl.add(Graph_lib::Point(150,200));
	cpl.add(Graph_lib::Point(250,250));
	cpl.add(Graph_lib::Point(300,200));
	cpl.add(Graph_lib::Point(100,250));
	//polygon
	Graph_lib::Polygon poly;
	poly.add(Graph_lib::Point(100,100));
	poly.add(Graph_lib::Point(150,200));
	poly.add(Graph_lib::Point(250,250));
	poly.add(Graph_lib::Point(300,200));

	//rectangle
	Graph_lib::Rectangle rect00{Graph_lib::Point{150,100},200,100};
	Graph_lib::Rectangle rect11{Graph_lib::Point{50,50},Graph_lib::Point{250,150}};
	Graph_lib::Rectangle rect12{Graph_lib::Point{50,150},Graph_lib::Point{250,250}}; 
	//just below rect11
	Graph_lib::Rectangle rect21{Graph_lib::Point{250,50},200,100};
	//just to the right of rect 11
	Graph_lib::Rectangle rect22{Graph_lib::Point{250,150},200,100};
	//just below rect 21

	rect00.set_fill_color(Color::yellow);
	rect11.set_fill_color(Color::blue);
	rect12.set_fill_color(Color::red);
	rect21.set_fill_color(Color::green);

	//win.attach(x);
	//win.attach(grid);
	//win.attach(opl);
	//win.attach(cpl);
	//win.attach(poly);
	win.attach(rect00);
	win.wait_for_button();
}
