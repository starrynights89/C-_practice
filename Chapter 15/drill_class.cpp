#include "Graph.h"
#include "Simple_window.h"
#include "Window.h"

struct Person
{
	Person() : first_n(""), second_n(""), a(0) { }
	Person(string fn, string sn, int age) :first_n(fn), second_n(sn), a(age) { }
    string first_name() const { return first_n; }
    string second_name() const { return second_n; }
    int age() const { return a; }
private:
    string first_n;
    string second_n;
    int a;
};

istream& operator>>(istream& is, Person& p)
{
    string fname, sname;
    int age;
    is >> fname >> sname >> age;
    if (!is) return is;
    p = Person(fname,sname,age);
    return is;
}

ostream& operator<<(ostream& os, const Person& p)
{
    return os << "Name: " << p.first_name() << ' ' 
        << p.second_name() << ", age: " << p.age();
}

int main()
{
}