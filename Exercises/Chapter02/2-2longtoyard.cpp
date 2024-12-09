#include<iostream>
using namespace std;
int longtoyard(int);

int main(){
    int longdistance;
    cout<<"The long is: ";
    cin>>longdistance;
    cout<<longdistance<<" long = "<<longtoyard(longdistance)<<" yard."<<endl;
    return 0;
}

int longtoyard(int n) 
{
    return n*220;
}