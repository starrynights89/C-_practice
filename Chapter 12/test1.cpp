#include "Graph.h"
#include "Simple_window.h"

int main()
{
	using namespace Graph_lib; //our graphics facilities are in Graph_lib

	Point tl(100, 100); //to become top left corner of window
	Simple_window win(tl, 600, 400, "Canvas"); //make a simple window

    //x Axis
    Axis xa {Axis::x, Point{20,300},280,10,"x axis"}; //make an Axis
    win.attach(xa); //attach xa to the window, win
    win.set_label("Canvas #2"); //relabel the window

    //y Axis
    Axis ya {Axis::y, Point{20,300},280,10,"y axis"};
    ya.set_color(Color::cyan); //chose a color
    ya.label.set_color(Color::dark_red); //choose a color for the text
    win.attach(ya);
    win.set_label("Canvas #3"); //display!

	win.wait_for_button(); //give control to the display engine
}