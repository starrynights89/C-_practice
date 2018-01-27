#include "std_lib_facilities.h"

void sizes(char ch, int i, int* p)
{
	cout << "the size of char is " << sizeof(char) << ' ' << sizeof(ch) << '\n';
	cout << "the size of int is " << sizeof(int) << ' ' << sizeof(i) << '\n';
	cout << "the size of int* is " << sizeof(int*) << ' ' << sizeof(p) << '\n';
}

int main()
{
	sizes(char ch, int i, int* p);
	return 0;
}
