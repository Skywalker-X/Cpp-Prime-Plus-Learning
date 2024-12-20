#include<iostream>
using namespace std;

double avg(double, double);

int main()
{
    double x, y;
    cin>>x>>y;
    cout<<avg(x,y);
    return 0;
}

double avg(double x, double y)
{
    return 2.0*x*y/(x+y);
}