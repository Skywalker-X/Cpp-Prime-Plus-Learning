#include<iostream>
using namespace std;

int main(){
    double celsius;
    cout<<"Please enter a Celsius value: ";
    cin>>celsius;
    double fahrenheit = 32+1.8*celsius;
    cout<<celsius<<" degrees Celsius is "<<fahrenheit<<" degrees Fahrenheit."<<endl;
    return 0;
}