#include<iostream>
#include<cstring>
using namespace std;

const int Len = 40;

class Golf
{
private:
    char fullname[Len];
    int handicap;
public:
    Golf(const char * name = "", int hc = 0);
    ~Golf();
    int setgolf();
    void sethandicap(int hc);
    void showgolf() const;
};


Golf::Golf(const char * name, int hc)
{
    strcpy(fullname, name);
    handicap = hc;
}

Golf::~Golf()
{
}

int Golf::setgolf()
{
    char name[Len];
    int hc;

    cout<<"Enter name: "<<endl;
    cin.getline(name, Len);
    cout<<"Enter hanicap: "<<endl;
    cin>>hc;

    *this = Golf(name, hc);

    if(this->fullname[0] == '\0')
        return 0;
    else
        return 1;
}

void Golf::sethandicap(int hc)
{
    handicap = hc;
}

void Golf::showgolf() const
{
    cout<<"Name: "<<fullname<<endl;
    cout<<"Handicap: "<<handicap<<endl;
}




int main()
{
    Golf ann("Ann Birdfree", 24);
    ann.showgolf();
    ann.sethandicap(28);
    ann.showgolf();

    Golf andy;
    int flag = andy.setgolf();
    andy.showgolf();
    cout<<flag;

    return 0;
}