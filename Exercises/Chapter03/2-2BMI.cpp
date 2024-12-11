#include<iostream>
int main(){
    using namespace std;
    const int foot2inch = 12;
    const double inch2meter = 0.0254;
    const double kg2pound = 2.2;

    int foot;
    int inch;
    double pound;

    cout<<"Input height in foot and inch."<<endl;
    cout<<"foot: __\b\b";
    cin>>foot;
    cout<<"inch: __\b\b";
    cin>>inch;
    cout<<"Input weight in pound: __\b\b";
    cin>>pound;

    double meter = (foot*foot2inch + inch) * inch2meter;
    double kg = pound/kg2pound;
    
    cout<<"BMI is "<< kg/(meter*meter)<<endl;
    return 0;
}