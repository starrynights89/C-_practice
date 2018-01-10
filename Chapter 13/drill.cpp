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
    //adding window
    Simple_window win(Graph_lib::Point(100,100), 800, 1000, "Grid");

    //adding grid
    Graph_lib::Lines grid;
    int x_size = 800;
    int y_size = 800;
    for (int i=100; i<=x_size; i+=100)
    {
        grid.add(Graph_lib::Point(i,0),Graph_lib::Point(i,y_size));
		grid.add(Graph_lib::Point(0, i), Graph_lib:: Point(x_size, i));
    }

    //make squares
    vector_ref<Rectangle>vr;
    for (int i=0; i<8; i++)
    {
        vr.push_back(new Graph_lib::Rectangle(Graph_lib::Point(i*100,i*100),101,101));
        vr[vr.size()-1].set_fill_color(Color::red);
        win.attach(vr[vr.size()-1]);
    }

    win.attach(grid);
    //win.resize(1000,800);
    win.wait_for_button();
}