#include "std_lib_facilities.h"

void main(double bo, int i, int* p)
{
	cout << "the size of double is " << sizeof(double) << ' ' << sizeof(bo) << '\n';
	cout << "the size of int is " << sizeof(int) << ' ' << sizeof(i) << '\n';
	cout << "the size of int* is " << sizeof(int*) << ' ' << sizeof(p) << '\n';
	keep_window_open();
}