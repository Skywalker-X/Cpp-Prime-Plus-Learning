#include<iostream>
int main(){
    using namespace std;
    int a, b, sum=0;
    cin>>a;
    cin>>b;
    for (int i=a; i<=b; i++)
        sum+=i;
    cout<<sum<<endl;
    return 0;
}