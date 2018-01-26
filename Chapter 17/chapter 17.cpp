#include "std_lib_facilities.h"

//a very simplified vector of doubles (like vector<double>)
class vector 
{
	int sz; //the size
	double* elem; //point to the first element (of type double)
public:
	vector(int s); //constructor: allocate s doubles,
				   //let elem point to them
				   //store s in sz
	int size() const { return sz; } //the current size
};