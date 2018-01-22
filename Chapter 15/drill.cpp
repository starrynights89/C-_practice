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

    constexpr int r_min = -10; //range [-10:11)
    constexpr int r_max = 11; 

    constexpr int n_points = 400; //number of points used in range

    constexpr int x_scale = 20; //scaling factors
    constexpr int y_scale = 20;

    constexpr int xlength = xmax-20; //make the axis a bit smaller than the window
    constexpr int ylength = ymax-20;

	Graph_lib::Window win(Point(100,100),xmax,ymax,"Function Graphs");

    Axis x(Axis::x,Point(20,y_orig),xlength,xlength/x_scale,"1 == 20 pixels");
    x.set_color(Color::red);
    win.attach(x);

    gui_main();
}