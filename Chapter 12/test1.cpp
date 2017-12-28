#include "Graph.h"
#include "Simple_window.h"

int main()
{
	using namespace Graph_lib; //our graphics facilities are in Graph_lib

	Point tl(100, 100); //to become top left corner of window
	Simple_window win(tl, 600, 400, "Canvas"); //make a simple window

    Axis xa {Axis::x, Point{20,300},280,10,"x axis"}; //make an Axis
    win.attach(xa); //attach xa to the window, win
    win.set_label("Canvas #2"); //relabel the window
	win.wait_for_button(); //give control to the display engine
}