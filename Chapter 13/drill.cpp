#include "Graph.h"
#include "Simple_window.h"

int main()
{
    //adding window
    Simple_window win(Point(100,100), 800, 1000, "Grid");

    //adding grid
    Lines grid;
    int x_size = 800;
    int y_size = 800;
    for (int i=100; i<=x_size; i+=100)
    {
        grid.add(Point(i,0),Point(i,y_size));
		grid.add(Point(0, i),Point(x_size, i));
    }

    //make squares that are red along a vertical line
    Vector_ref<Graph_lib::Rectangle>vr;
    for (int i=0; i<8; i++)
    {
		vr.push_back(new Graph_lib::Rectangle(Point(i * 100, i * 100), 101, 101));
        vr[vr.size()-1].set_fill_color(Color::red);
        win.attach(vr[vr.size()-1]);
    }

    //place 3 copies of a 200x200 image, don't cover the red squares
    Image plane1(Point(200,0),"C://Users//alexa//source//repos//"
	"chapter13_practice c++//Release//image.jpg");
    Image plane2(Point(400,200),"C://Users//alexa//source//repos//"
	"chapter13_practice c++//Release//image.jpg");
    Image plane3(Point(600,400),"C://Users//alexa//source//repos//"
	"chapter13_practice c++//Release//image.jpg");

    //place 100x100 that moves with clicking next
    Image anime(Point(0,0),"C://Users//alexa//source//repos//"
	"chapter13_practice c++//Release//image1.png");

    int x = 0;
    int y = 0;
    int dx = 0;
    int dy = 0;
    while(true)
    {
        x = randint(8);
        y = randint(8);
        dx = 100*x - anime.point(0).x;
        dy = 100*y - anime.point(0).y;
        anime.move(dx,dy);
    }

    win.attach(grid);
    win.resize(1000,800);
    win.attach(plane1);
	win.attach(plane2);
	win.attach(plane3);
    win.attach(anime);
    win.wait_for_button();
}