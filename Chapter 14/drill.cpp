//Chapter 14 drill

#include "std_lib_facilities.h"

class B1
{
public:
    virtual void vf() { cout << "B1::vf()\n"; }
    void f() { cout << "B1::f()\n"; }
    //virtual void pvf() =0;
};

class D1 : public B1
{
public:
    void vf() { cout << "D1::vf()\n"; }
    void f() { cout << "D1::f()\n"; }
};

class D2 : public D1
{
public:
    void pvf() { cout << "D2::pvf()\n"; }
};

int main()
{
    B1 b1;
    b1.vf();
    b1.f();

    D1 d1;
    d1.vf();
    d1.f();

    keep_window_open();
}