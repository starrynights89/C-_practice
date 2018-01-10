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
    for (int i = 100; i<=x_size; i+=100)
    {
        grid.add(Point(i,0),Point(i,y_size));
        grid.add(Point(0,i),Point(x_size,i));
    }

    win.attach(grid);
    win.wait_for_button();
}