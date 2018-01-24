#include "Simple_window.h"
#include "Graph.h"

struct Simple_window : Graph_lib::Window
{
    Simple_window(Point xy,int w,int h,const string & title);
    void wait_for_button(); //simple event loop
private:
    Button next_button; //the "Next" button
    bool button_pushed; //implementation detail

    static void cb_next(Address,Address); //callback for next_button
    void next(); //action to be done when next_button is pressed
};

//constructor
Simple_window::Simple_window(Point xy,int w,int h,const string& title)
    :Window(xy,w,h,title),
    next_button(Point(x_max()-70,0),70,20,"Next",cb_next),
    button_pushed(false)
{
    attach(next_button);
}

void Simple_window::cb_next(Address,Address pw)
//call Simple_window::next() for the window located at pw
{
    reference_to<Simple_window>(pw).next();
}

void Simple_window::wait_for_button()
    //modified event loop:
    //handle all events (as per default), quit when button_pushed becomes true
    //this allows graphics without control inversion
{
    while(!button_pushed) Fl::wait();
    button_pushed = false;
    Fl::redraw();
}

void Simple_window::next()
{
    button_pushed = true;
}

int main()
{
    Simple_window win();
    //create some object and/or manipulate some objects, display them in a window
    win.wait_for_button(); //next() causes the program to proceed from here
    //create some objects and/or manipulate some objects
}
