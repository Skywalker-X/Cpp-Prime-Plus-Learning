#include<iostream>
#include<string>
using namespace std;

struct CandyBar
{
    string name;
    double weight;
    int heat;
};

void init(CandyBar & cb, const string n="Millennium Munch", const double w=2.85, const int h=350)
{
    cb.name = n;
    cb.weight = w;
    cb.heat = h;
}

void show(const CandyBar & cb)
{
    cout<<cb.name<<" "<<cb.weight<<" "<<cb.heat<<endl;
}

int main()
{
    CandyBar c1, c2, c3, c4;
    init(c1);
    init(c2, "xx");
    init(c3, "xxx", 2.5);
    init(c4, "xxxx", 4.2, 400);
    show(c1);
    show(c2);
    show(c3);
    show(c4);
    return 0;
}