#include "Graph.h"
#include "Simple_window.h"

struct Distribution
{
    int year, young, middle, old;
};

istream& operator>>(istream& is, Distribution& d)
    //assume format: (year : young middle old)
{
    char ch1 = 0;
    char ch2 = 0;
    char ch3 = 0;
    Distribution dd;

    if(is >> ch1 >> dd.year
          >> ch2 >> dd.young >> dd. middle >> dd.old
          >> ch3)
    {
        if(ch1!='('||ch2!=':'||ch3!=')')
        {
            is.clear(ios_base::failbit);
            return is;
        }
    }
    else
    {
        return is;
    }
    d = dd;
    return is;
}

string file_name = "japanese-age-data.txt";
ifstream ifs {file_name};
if(!ifs) error("can't open",file_name);

for (Distribution d; ifs>>d;)
{
    if(d.year<base_year || end_year<d.year)
    {
        error("year out of range");
    }
    if(d.year+d.middle+d.old!=100)
    {
        error("percentages don't add up");
    }
}