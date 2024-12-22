#include <iostream>
#include <cstring>

using namespace std;

struct stringy {
    char *str;
    int ct;
};

void set(stringy& s, const char* source) 
{
    s.ct = strlen(source);
    s.str = new char[s.ct + 1];
    strcpy(s.str, source);
}

void show(const stringy& s, int n) 
{
    for (int i = 0; i < n; ++i) 
        cout << s.str << endl;
}

void show(const stringy& s) 
{
    cout << s.str << endl;
}

void show(const char* s, int n) 
{
    for (int i = 0; i < n; ++i)
        cout << s << endl;
}

void show(const char* s) 
{
    cout << s << endl;
}

int main() {
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");

    return 0;
}