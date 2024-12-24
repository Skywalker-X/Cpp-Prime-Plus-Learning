#include<iostream>
#include<cstring>
using namespace std;

struct chaff {
    char dross[20];
    int slag;
};

int num = 2;

int main()
{
    double buffer[80];
    
    chaff *ch = new (buffer) chaff[num];

    for(int i=0; i<num; i++)
    {
        cout<<ch[i].dross<<endl;
        cout<<ch[i].slag<<endl;
    }

    return 0;
}