#include "std_lib_facilities.h"

class Link
{
public:
    string value; 

    Link(const string& v, Link* p = nullptr, Link* s = nullptr)
         :value{v}, prev{p}, succ{s} { }

    Link* insert(Link* n);
    Link* add(Link* n);
    Link* erase();
    Link* find(const string& s);
    const Link* find(const string& s) const;

    Link* advance(int n) const;

    Link* next() const { return succ; }
    Link* previous() const { return prev; }
private:
    Link* prev;
    Link* succ;
};

Link* Link::insert(Link* n)
{
    Link* p = this;
    if(n==nullptr) return p;
    if(p==nullptr) return n;
    n->succ = p;
    if(p->prev)p->prev->succ = n;
    n->prev=p->prev;
    p->prev=n;
    return n;
}

Link* norse_gods = new Link("Thor");
norse_gods = insert(norse_gods,new Link{"Odin"});
norse_gods = insert(norse_gods,new Link{"Zeus"});
norse_gods = insert(norse_gods,new Link{"Freia"});

Link* greek_gods = new Link("Hera");

