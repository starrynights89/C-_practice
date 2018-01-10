#include "Graph.h"
#include "Simple_window.h"

int main()
{
    //adding window
    Simple_window win(Graph_lib::Point(100,100), 800, 1000, "Grid");

    //adding grid
    Graph_lib::Lines grid;
    

    win.wait_for_button();
}