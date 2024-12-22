#include<iostream>
using namespace std;

int count = 0;

void print(const char * str)
{
    cout<<str<<endl;
}

void print(const char * str, int n)
{
    if(n)
    {
        count++;
        for(int i=0; i<count; i++)
            cout<<str<<" "<<count<<endl;
    }
}

int main()
{
    print("xxx");
    print("xxxx", 1);
    print("xxxx", 0);
    print("xxxx", 1);
    return 0;
}