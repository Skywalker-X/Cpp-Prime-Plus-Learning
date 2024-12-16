#include<iostream>
int main(){
    using namespace std;
    double a, sum=0;
    cin>>a;
    while (a!=0)
    {
        sum += a;
        cout<<sum<<endl;
        cin>>a;
    }

    return 0;    
}