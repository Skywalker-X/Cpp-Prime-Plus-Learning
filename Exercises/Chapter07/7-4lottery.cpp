#include<iostream>
long double probility(unsigned numbers, unsigned picks);
int main(){
    using namespace std;
    
    cout<<"You have one chance in ";
    cout<<probility(47,5)*probility(27,1);
    cout<<" of winning.\n";
    cout<<"Next two numbers (q to quit): ";
    
    cout<<"bye\n";
    return 0;
}

long double probility(unsigned numbers, unsigned picks)
{
    long double result = 1.0;
    long double n;
    unsigned p;

    for (n=numbers, p=picks; p>0; n--, p--)
        result = result *n /p;
    
    return result;
}