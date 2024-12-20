#include<iostream>
using namespace std;

double add(double x, double y)
{
    return x+y;
}

double multi(double x, double y)
{
    return x*y;
}

double subtract(double x, double y)
{
    return x-y;
}

double calculate(double x, double y, double (*cal)(double, double))
{
    return cal(x,y);
}

int main()
{
    double x, y;
    cin>>x>>y;

    double (*pf[3])(double, double) = {add, subtract, multi};
    for (int i=0; i<3; i++)
    {
        cout<<pf[i](x,y)<<endl;
    }

    return 0;
}