#include "Simple_window.h"
#include "Graph.h"

class Person {
    string first, second;
    int years;

    bool check (string n) {
        if (int(n.size()) < 1 || isspace(n[0]) || isspace(n[n.size()-1]))
            return false;
        bool space = false;
        for (int i = 0; i < int(n.size()); ++i)
            if (! space && isspace(n[i]))
                space = true;
            else if (! isalnum(n[i]) && n[i] != '-' && n[i] != '_' &&
                    n[i] != '.' && n[i] != ',' &&  n[i] != '/' &&
                    n[i] != '(' && n[i] != ')')
                return false;
        return space;
    }
public:
    Person(string n, int a) : years(a) {
        if (! check(n)) error("That isn't a name");
        string s;
        for (int i = 0; i < int(n.size()); ++i)
            if (isspace(n[i])) {
                first = s;
                s = "";
            } else
                s += n[i];
        second = s;
        if (years < 0 || years > 150) error ("That isn't an age");
    }
    Person () : first("Anonnie"), second("Mouse"), years(999) {}
    Person (const Person & arg) :
        first(arg.first), second(arg.second), years(arg.years) {}
    const string name () const {return first+" "+second;}
    const int age () const {return years;}
};

istream & operator>> (istream & stream, Person & arg) {
    string s1, s2;
    int a;
    stream >> s1 >> s2 >> a;
    if (! stream) return stream;
    Person p(s1+" "+s2,a);
    arg = p;
    return stream;
}

ostream & operator<< (ostream & stream, const Person & arg) {
    stream << arg.name() << " is " << arg.age();
    return stream;
}

int main () {
    vector<Person> gnomes;
    gnomes.push_back(Person("Goofy Dawg",63));
    Person p;
    while (cin >> p) gnomes.push_back(p);
    for (int i = 0; i < int(gnomes.size()); ++i)
        cout << gnomes[i] << endl;
}