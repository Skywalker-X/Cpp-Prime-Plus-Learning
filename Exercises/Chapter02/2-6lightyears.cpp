#include<iostream>
using namespace std;

double lightyear(double);

int main()
{
    double light;
    cout<<"Enter the number of light years: ";
    cin>>light;
    cout<<light<<" light years = "<<lightyear(light)<<" astronomical units."<<endl;
    return 0;
}

double lightyear(double n)
{
    return n*63240;
}