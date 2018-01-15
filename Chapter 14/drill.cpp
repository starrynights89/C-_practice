//Chapter 14 drill

#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

class B1
{
public:
    virtual void vf() { cout << "B1::vf()\n"; }
    void f() { cout << "B1::f()\n"; }
    //virtual void pvf() =0;
};

int main()
{
    B1 b1;
    b1.vf();
    b1.f();

    keep_window_open();
}