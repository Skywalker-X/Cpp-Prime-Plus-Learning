#include<iostream>
using namespace std;

void showtime(int,int);

int main(){
    int hour, minute;
    cout<<"Enter the number of hours: ";
    cin>>hour;
    cout<<"Enter the number of minutes: ";
    cin>>minute;
    showtime(hour, minute);
    return 0;
}

void showtime(int h, int m)
{
    cout<<h<<":"<<m<<endl;
}