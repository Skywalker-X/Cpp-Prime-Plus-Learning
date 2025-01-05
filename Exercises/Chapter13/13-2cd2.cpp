#include<iostream>
#include<cstring>
using namespace std;

class Cd
{
private:
    char * performers;
    char * label;
    int selections;
    double playtime;
public:
    Cd(const char * s1, const char * s2, int n, double x);
    Cd(const Cd & d);
    Cd();
    virtual ~Cd();
    virtual void Report() const;
    Cd & operator=(const Cd & d);
};

Cd::Cd(const char * s1, const char * s2, int n, double x)
{
    performers = new char[strlen(s1) + 1];
    strcpy(performers, s1);
    label = new char[strlen(s2) + 1];
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d)
{
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    performers = new char[1];
    performers[0] = '\0';
    label = new char[1];
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd()
{
    delete [] performers;
    delete [] label;
}

void Cd::Report() const
{
    cout << "Performers: " << performers << endl;
    cout << "Label: " << label << endl;
    cout << "Selections: " << selections << endl;
    cout << "Playtime: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d)
{
    if(this == &d)
        return *this;
    delete [] performers;
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);
    delete [] label;
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

class Classic : public Cd
{
private:
    char * main;
public:
    Classic(const char * m, const char * s1, const char * s2, int n, double x);
    Classic(const char * m, const Cd & d);
    Classic(const Classic & c);
    Classic();
    ~Classic();
    virtual void Report() const;
    Classic & operator=(const Classic & c);
};

Classic::Classic(const char * m, const char * s1, const char * s2, int n, double x)
     : Cd(s1, s2, n, x)
{
    main = new char[strlen(m) + 1];
    strcpy(main, m);
}

Classic::Classic(const char * m, const Cd & d) : Cd(d)
{
    main = new char[strlen(m) + 1];
    strcpy(main, m);
}

Classic::Classic(const Classic & c) : Cd(c)
{
    main = new char[strlen(c.main) + 1];
    strcpy(main, c.main);
}

Classic::Classic()
{
    main = new char[1];
    main[0] = '\0';
}

Classic::~Classic()
{
    delete [] main;
}

void Classic::Report() const
{
    Cd::Report();
    cout << "Main: " << main << endl;
}

Classic & Classic::operator=(const Classic & c)
{
    if(this == &c)
        return *this;
    Cd::operator=(c);
    delete [] main;
    main = new char[strlen(c.main) + 1];
    strcpy(main, c.main);
    return *this;
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