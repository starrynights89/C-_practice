#include "Graph.h"
#include "Simple_window.h"

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

    //make squares that are red along a vertical line
    Vector_ref<Graph_lib::Rectangle>vr;
    for (int i=0; i<8; i++)
    {
		vr.push_back(new Graph_lib::Rectangle(Graph_lib::Point(i * 100, i * 100), 101, 101));
        vr[vr.size()-1].set_fill_color(Color::red);
        win.attach(vr[vr.size()-1]);
    }

    //place 3 copies of a 200x200 image, don't cover the red squares
    Image plane1(Point(200,0),"C://Users//alexa//source//repos//"
	"chapter13_practice c++//Release//image.jpg");

    win.attach(grid);
    win.resize(1000,800);
    win.attach(plane1);
    win.wait_for_button();
}