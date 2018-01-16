#include "Graph.h"
#include "Simple_window.h"

double one(double) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x)+slope(x); }

int main()
{
    constexpr int xmax = 600; //window size
    constexpr int ymax = 400; 

    constexpr int x_orig = xmax/2; //position of (0,0) is center of window
    constexpr int y_orig = ymax/2;
    const Point orig(x_orig,y_orig);

    constexpr int r_min = -10; //range [-10:11)
    constexpr int r_max = 11; 

    constexpr int n_points = 400; //number of points used in range

    constexpr int x_scale = 30; //scaling factors
    constexpr int y_scale = 30;

    constexpr int xlength = xmax-40; //make the axis a bit smaller than the window
    constexpr int ylength = ymax-40;

    Simple_window win {Point{100,100},xmax,ymax,"Function graphing"};

    Axis x(Axis::x,Point(20,y_orig),
          xlength,xlength/x_scale,"one notch == 1");
    x.set_color(Color::red);
    win.attach(x);
    win.wait_for_button();

    Axis y(Axis::y,Point(x_orig,ylength+20),
          ylength,ylength/y_scale,"one notch == 1");
    y.set_color(Color::red);
    win.attach(y);
    win.wait_for_button();

    Function s(one,r_min,r_max,orig,n_points,x_scale,y_scale);
    Text ts(Point(100,y_orig-40),"one");
    win.attach(s);
    win.attach(ts);
    win.wait_for_button();

    Function s2(slope,r_min,r_max,orig,n_points,x_scale,y_scale);
    Text ts2(Point(100,y_orig+y_orig/2-20),"x/2");
    win.attach(s2);
    win.attach(ts2);
    win.wait_for_button();

    Function s3(square,r_min,r_max,orig,n_points,x_scale,y_scale);
    Text ts3(Point(x_orig-100,20),"x*x");
    win.attach(s3);
    win.attach(ts3);
    win.set_label("Function graphing: label functions");
    win.wait_for_button();

    Function s4(cos,r_min,r_max,orig,400,30,30);
    s4.set_color(Color::blue);
    win.attach(s4);
    win.wait_for_button();

    Function s5(sloping_cos,r_min,r_max,orig,400,30,30);
    win.attach(s5);
    x.label.move(-160,0);
    x.notches.set_color(Color::dark_red);
    win.set_label("Function graphing: more functions");
    win.wait_for_button();

    Function f1(log,0.0000001,r_max,orig,200,30,30); //log() logarithm, base e
    win.atach(f1);
    win.wait_for_button();

    Function f2(sin,r_min,r_max,orig,200,30,30); //sin()
    f2.set_color(Color::blue);
    win.attach(f2);
    win.wait_for_button();

    Function f3(cos,r_min,r_max,orig,200,30,30); //cos()
    win.attach(f3);
    win.wait_for_button();

    Function f4(exp,r_min,r_max,orig,200,30,30); //exp() exponential e^x
    win.attach(f4);
    win.wait_for_button();
}