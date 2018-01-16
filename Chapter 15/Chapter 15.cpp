#include "Graph.h"
#include "Simple_window.h"

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }

int main()
{
    const int xmax = 600; //window size
    const int ymax = 400; 

    const int x_orig = xmax/2; //position of (0,0) is center of window
    const int y_orig = ymax/2;
    const Point orig {x_orig,y_orig};

    const int r_min = -10; //range [-10:11)
    const int r_max = 11; 

    const int n_points = 400; //number of points used in range

    const int x_scale = 30; //scaling factors
    const int y_scale = 30;

    Simple_window win {Point{100,100},xmax,ymax,"Function graphing"};

    Function s {one,r_min,r_max,orig,n_points,x_scale,y_scale};
    Function s2 {slope,r_min,r_max,orig,n_points,x_scale,y_scale};
    Function s3 {square,r_min,r_max,orig,n_points,x_scale,y_scale};

    win.attach(s);
    win.attach(s2);
    win.attach(s3);
    win.wait_for_button();
}