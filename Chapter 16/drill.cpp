/*
This program has the user put in x and y
coordinates to draw shapes
*/

#include "Simple_window.h"
#include "Graph.h"

struct Lines_window : Window
{
    Lines_window(Point xy,int w,int h,const string& title);
    Open_polyline lines;
private:
    //widgets
    Button next_button; //add (next_x,next_y) to lines
    Button quit_button;
    In_box next_x;
    In_box next_y;
    Out_box xy_out;

    void next();
    void quit();
};

//add constructor
Lines_window::Lines_window(Point xy,int w,int h,const string& title)
    :Window(xy,w,h,title),
    next_button(Point(x_max()-150,0),70,20,"Next point",
        [](Adress,Address pw) { reference_to<Lines_window>(pw).next(); },
    quit_button(Point())