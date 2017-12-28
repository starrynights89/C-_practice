#include "Graph.h"
#include "Simple_window.h"

int main()
{
	using namespace Graph_lib; //our graphics facilities are in Graph_lib

	Point tl(100, 100); //to become top left corner of window

	Simple_window win(tl, 600, 400, "Canvas"); //make a simple window

	win.wait_for_button(); //give control to the display engine
}