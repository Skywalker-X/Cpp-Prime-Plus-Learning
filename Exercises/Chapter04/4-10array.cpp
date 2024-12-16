#include<iostream>
#include<array>
int main(){
    using namespace std;

    array<double, 3> result;

    cout<<"Enter three results: "<<endl;
    cin>>result[0];
    cin>>result[1];
    cin>>result[2];

    cout<<"There are "<<result.size()<<" times. \n";
    cout<<"Average: "<<(result[0]+result[1]+result[2])/3<<endl;

    return 0;
}