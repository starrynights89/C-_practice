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
        grid.add(Point(i,0),Point(i,y_size));
        grid.add(Point(0,i),Point(x_size,i));
    }

    //make squares
    vector_ref<Graph_lib::Rectangle>vr;
    for (int i=0; i<8; i++)
    {
        vr.push_back(new Graph_lib::Rectangle(Point(i*100,i*100),101,101));
        vr[vr.size()-1].set_fill_color(Color::red);
        win.attach(vr[vr.size()-1]);
    }

    win.attach(grid);
    //win.resize(1000,800);
    win.wait_for_button();
}