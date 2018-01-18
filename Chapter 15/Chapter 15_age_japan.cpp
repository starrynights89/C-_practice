#include "Graph.h"
#include "Simple_window.h"

struct Distribution
{
    int year, young, middle, old;
};

istream& operator>>(istream& is, Distribution& d)
    //assume format: (year : young middle old)
{
    char ch1 = 0;
    char ch2 = 0;
    char ch3 = 0;
    Distribution dd;
}