#include<iostream>
int main(){
    using namespace std;
    const int second2minute = 60;
    const int minute2hour = 60;
    const int hour2day = 24;
    long long secondtime;

    cout<<"Enter the number of seconds: ";
    cin>>secondtime;

    int days = secondtime / second2minute / minute2hour / hour2day;
    int hours = (secondtime / second2minute / minute2hour)%hour2day;
    int minutes = (secondtime / second2minute)%minute2hour;
    int seconds = secondtime%second2minute;
    
    cout<<secondtime<<"seconds = "<<days<<" days, "<<hours<<" hours, "<<minutes<<" minutes, "<<seconds<<" seconds."<<endl;
    return 0;
}