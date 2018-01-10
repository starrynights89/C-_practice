#include "Graph.h"
#include "Simple_window.h"

int main()
{
    Simple_window win(Graph_lib::Point(100,100), 800, 1000, "Grid");

    win.wait_for_button();
}