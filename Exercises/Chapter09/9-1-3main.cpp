#include<iostream>
#include"9-1-1golf.h"
using namespace std;

int main()
{
    golf ann;
    setgolf(ann, "Ann Birdfree", 24);
    showgolf(ann);
    handicap(ann, 28);
    showgolf(ann);

    golf andy;
    int flag = setgolf(andy);
    showgolf(andy);
    cout<<flag;

    return 0;
}