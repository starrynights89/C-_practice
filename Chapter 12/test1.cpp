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

    //sine curve
    Function sine {sin,0,100,Point{20,150},1000,50,50}; //sine curve
    //plot sin() in the range [:100) with (0,0) at (20,150)
    //using 1000 points; scale x values * 50, scale y values *50
    win.attach(sine);
    win.set_label("Canvas #4");

    //polygon
    sine.set_color(Color::blue); //we changed our mind about sine's color
    Graph_lib::Polygon poly; //a polygon; a Polygon is a kind of Shape
    poly.add(Point{300,200}); //three points make a triangle
    poly.add(Point{350,100});
    poly.add(Point{400,200});
    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    win.attach(poly);
    win.set_label("Canvas #5");

    //rectangle
    Graph_lib::Rectangle r {Point{200,200},100,50}; //top left corner, width, height
    win.attach(r);
    win.set_label("Canvas #6");

    //closed polyline
    Closed_polyline poly_rect;
    poly_rect.add(Point{100,50});
    poly_rect.add(Point{200,50});
    poly_rect.add(Point{200,100});
    poly_rect.add(Point{100,100});
    poly_rect.add(Point{50,75});
    win.attach(poly_rect);

    //adding colors
    r.set_fill_color(Color::yellow); //color the inside of the rectangle
    poly.set_style(Line_style(Line_style::dash,4));
    poly_rect.set_style(Line_style(Line_style::dash,2));
    poly_rect.set_fill_color(Color::green);
    win.set_label("Canvas #7");
    
	win.wait_for_button(); //give control to the display engine
}