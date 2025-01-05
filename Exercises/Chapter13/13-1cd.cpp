#include<iostream>
#include<cstring>
using namespace std;

class Cd
{
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;
public:
    Cd(const char * s1, const char * s2, int n, double x);
    Cd();
    virtual ~Cd();
    virtual void Report() const;
};

Cd::Cd(const char * s1, const char * s2, int n, double x)
{
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd()
{
    strcpy(performers, "No name");
    strcpy(label, "No label");
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd()
{
}

void Cd::Report() const
{
    cout << "Performers: " << performers << endl;
    cout << "Label: " << label << endl;
    cout << "Selections: " << selections << endl;
    cout << "Playtime: " << playtime << endl;
}

class Classic : public Cd
{
private:
    char main[50];
public:
    Classic(const char * m, const char * s1, const char * s2, int n, double x);
    Classic(const char * m, const Cd & d);
    Classic();
    virtual ~Classic();
    virtual void Report() const;
};

Classic::Classic(const char * m, const char * s1, const char * s2, int n, double x) 
     : Cd(s1, s2, n, x)
{
    strncpy(main, m, 49);
    main[49] = '\0';
}

Classic::Classic(const char * m, const Cd & d) : Cd(d)
{
    strncpy(main, m, 49);
    main[49] = '\0';
}

Classic::Classic()
{
    main[0] = '\0';
}

Classic::~Classic()
{
}

void Classic::Report() const
{
    Cd::Report();
    cout << "Main: " << main << endl;
}

void Bravo(const Cd & disk)
{
    disk.Report();
}

int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2("Piano Sonata in B flat, Fantasia in C", 
        "Alfred Brendel", "Philips", 2, 57.17);
    Cd *pcd = &c1;

    cout << "Using object directly:\n";
    c1.Report();
    c2.Report();

    cout << "Using type cd * pointer to objects:\n";
    pcd->Report();
    pcd = &c2;
    pcd->Report();

    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);

    cout << "Testing assignment: \n";
    Classic copy;
    copy.Report();
    copy = c2;
    copy.Report();

    return 0;
}