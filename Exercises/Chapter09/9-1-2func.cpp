#include<iostream>
#include<cstring>
#include"9-1-1golf.h"
using namespace std;

void setgolf(golf & g, const char * name, int hc)
{
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf & g)
{
    cout<<"Enter name: "<<endl;
    cin.getline(g.fullname, Len);
    cout<<"Enter hanicap: "<<endl;
    cin>>g.handicap;

    if(g.fullname[0] == '\0')
        return 0;
    else
        return 1;
}

void handicap(golf & g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf & g)
{
    cout<<"Name: "<<g.fullname<<endl;
    cout<<"Handicap: "<<g.handicap<<endl;
}