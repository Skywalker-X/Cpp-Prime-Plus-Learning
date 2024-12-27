#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Person 
{
private:
    static const int LIMIT = 25;
    string lname;
    char fname[LIMIT];
 
public:
    Person() { lname = ""; fname[0] = '\0'; }
    Person(const string & ln, const char * fn = "Heyyou");
    void Show() const;
    void FormalShow() const;
};

Person::Person(const string & ln, const char * fn) {
    lname = ln; 
    strncpy(fname, fn, LIMIT - 1);
    fname[LIMIT - 1] = '\0';
}

void Person::Show() const
{
    cout<<fname<<" "<<lname<<endl;
}

void Person::FormalShow() const
{
    cout<<lname<<" "<<fname<<endl;
}

int main()
{
    Person one;
    Person two("Smythecraft");
    Person three("Dimwidy", "Sam");

    one.Show();
    one.FormalShow();
    two.Show();
    two.FormalShow();
    three.Show();
    three.FormalShow();

    return 0;
}