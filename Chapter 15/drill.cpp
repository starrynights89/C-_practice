#include "Graph.h"
#include "Simple_window.h"
#include "Window.h"

int main()
{
    constexpr int xmax = 600; //window size
    constexpr int ymax = 600; 

    constexpr int x_orig = xmax/2; //position of (0,0) is center of window
    constexpr int y_orig = ymax/2;
    const Point orig(x_orig,y_orig);

	Graph_lib::Window win(Point(100,100),xmax,ymax,"Function Graphs");

    gui_main();
}