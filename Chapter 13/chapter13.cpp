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

	//adding text
	Text t{Graph_lib::Point{200,200},"A closed polyline that isn't a polygon"};
	t.set_color(Color::blue);
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

	rect11.move(400,0); //to the right of rect21
	rect11.set_fill_color(Color::white);
	win.set_label("rectangles 2");

	win.put_on_top(rect00);
	win.set_label("rectangles 3");

	rect00.set_color(Color::invisible);
	rect11.set_color(Color::invisible);
	rect12.set_color(Color::invisible);
	rect21.set_color(Color::invisible);
	rect22.set_color(Color::invisible);

	/*
	Vector_ref<Graph_lib::Rectangle>vr;
	for(int i=0; i<16; i++)
	{
		for(int j=0; j<16; j++)
		{
			vr.push_back(new Graph_lib::Rectangle{Graph_lib::Point{i*20,j*20},20,20});
			vr[vr.size()-1].set_fill_color(Color{i*16+j});
			win.attach(vr[vr.size()-1]);
		}
	}
	*/

	//adding circle
	Circle c1{Graph_lib::Point{100,200},50};
	Circle c2{Graph_lib::Point{150,200},100};
	Circle c3{Graph_lib::Point{200,200},150};

	//adding Ellipse
	Graph_lib::Ellipse e1{Graph_lib::Point{200,200},50,50};
	Graph_lib::Ellipse e2{Graph_lib::Point{200,200},100,50};
	Graph_lib::Ellipse e3{Graph_lib::Point{200,200},100,150};

	//marked polyline
	Marked_polyline mpl{"1234"};
	mpl.add(Graph_lib::Point{100,100));
	mpl.add(Graph_lib::Point{150,200));
	mpl.add(Graph_lib::Point{250,250));
	mpl.add(Graph_lib::Point{300,200));

	//win.attach(x);
	//win.attach(grid);
	//win.attach(opl);
	//win.attach(cpl);
	//win.attach(t);
	//win.attach(poly);
	//win.attach(rect00);
	//win.attach(rect11);
	//win.attach(rect12);
	//win.attach(rect21);
	//win.attach(rect22);
	//win.attach(c1);
	//win.attach(c2);
	//win.attach(c3);
	//win.attach(e1);
	//win.attach(e2);
	//win.attach(e3);
	win.attach(mpl);
	win.wait_for_button();
}
