#include "std_lib_facilities.h"

//a very simplified vector of doubles
class vector
{
	int sz; //the size
	double* elm; //a pointer to the elements
public:
	vector(int s):sz{s}, elem{new double[s]} {/*...*/} //constructor
	~vector() { delete[] elem; } 
	
	int size() const { return sz; } //the current size
	
	double get(int n) const{ return elem[n]; } //access : read
	void set(int n, double v) { elem[n]=v; } //access : write
};

vector<T>vector;

int main()
{
	vector v(5);
	for (int i=0; i<v.size(); i++)
	{
		v.set(i,1.1*i);
		cout << "v[" << i << "]==" << v.get(i) << '\n';
	}
}