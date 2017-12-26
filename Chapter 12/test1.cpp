#include "std_lib_facilities.h"
#include "Simple_window.h" //get access to our window library
#include "Graph.h"  //get access to our grapihcs library facilities

int main()
{
    using namespace Graph_lib; //our graphics facilities are in Graph_lib

    Point tl {100,100} //to become top left corner of window

    Simple_window win {tl,600,400,"Canvas"; //make a simple window

    Polygon poly; //make a shape (a polygom)

    poly.add(Point{300,200}); //add a point
    poly.add(Point{350,100}); //add another point
    poly.add(Point{400,200}); //add a third point

    poly.set_color(Color::red); //adjust propertires of poly

    win.attach (poly); //connect polt to the window

    win.wait_for_button(); //give control to the display engine
}