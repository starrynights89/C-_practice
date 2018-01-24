#include "Simple_window.h"
#include "Graph.h"

struct Simple_window : Graph_lib::Window
{
    Simple_window(Point xy,int w,int h,const string & title);
    void wait_for_button(); //simple event loop
private:
    Graph_lib::Button next_button; //the "Next" button
    bool button_pushed; //implementation detail

    static void cb_next(Address,Address); //callback for next_button
    void next(); //action to be done when next_button is pressed
};

struct Button : Graph_lib::Widget
{
    Button(Point xy,int ww,int hh,const string& s, Callback cb)
        :Widget{xy,ww,hh,s,cb} { }
    void attach(Graph_lib::Window& win);
};

class Widget
{
	//Widget is a handle to an Fl_widget - it is *not* an Fl_widget
	//we try to keep our interface classes at arm's length from FLTK
public:
	Widget(Point xy,int w,int h,const string& s, Callback cb);

    virtual void move(int dx,int dy);
    virtual void hide();
    virtual void show();
    virtual void attach(Graph_lib::Window&) = 0;

    Point loc;
    int width;
    int height;
    string label;
    Callback do_it;
protected:
    Graph_lib::Window* own; //every Widget belongs to a Window
    Fl_Widget* pw; //connection to the FLTK Widget
};

struct In_box : Graph_lib::Widget
{
    In_box(Point xy,int w, int h,const string& s)
        :Widget{xy,w,h,s,0} { }
    int get_int();
    string get_string();

    void attach(Graph_lib::Window& win);
};

struct Out_box : Graph_lib::Widget
{
    Out_box(Point xy,int w,int h, const string& s)
        :Widget{xy,w,h,s,0} { }
    void put(int);
    void put(const string&);

    void attach(Graph_lib::Window& win);
};

//constructor
Simple_window::Simple_window(Point xy,int w,int h,const string& title)
	:Window{ xy,w,h,title },
	next_button{ Point{x_max() - 70,0},70,20,"Next",
		[](Address,Address pw) {reference_to<Simple_window>
		(pw).next(); }
},
    button_pushed(false)
{
    attach(next_button);
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
    //create some object and/or manipulate some objects, display them in a window
    win.wait_for_button(); //next() causes the program to proceed from here
    //create some objects and/or manipulate some objects
}
