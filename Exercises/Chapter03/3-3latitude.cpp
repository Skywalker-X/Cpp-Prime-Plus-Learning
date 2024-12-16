#include<iostream>
int main(){
    using namespace std;
    const double degree2minute = 60;
    const double minute2second = 60;
    double degree, minute, second;

    cout<<"Enter a latitude in degrees, minutes, and seconds:\n";
    cout<<"First, enter the degrees: ";
    cin>>degree;
    cout<<"Next, enter the minutes of arc: ";
    cin>>minute;
    cout<<"Finally, enter the seconds of arc: ";
    cin>>second;

    double latitude = degree + (minute + second / minute2second) / degree2minute;
    cout<<degree<<" degrees, "<<minute<<" minutes, "<<second<<" seconds = "<<latitude<<" degrees"<<endl;
    return 0;
}