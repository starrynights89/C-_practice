#include "std_lib_facilities.h"

void sizes(char, int, int*);

int main()
{
	char a = 0;
	int b = 0; 
	int* c = 0; 
	
	sizes(a, b, c);
	keep_window_open();
	return 0;
}

void sizes(char ch, int i, int* p)
{
	cout << "the size of char is " << sizeof(char) << ' ' << sizeof(ch) << '\n';
	cout << "the size of int is " << sizeof(int) << ' ' << sizeof(i) << '\n';
	cout << "the size of int* is " << sizeof(int*) << ' ' << sizeof(p) << '\n';
}
