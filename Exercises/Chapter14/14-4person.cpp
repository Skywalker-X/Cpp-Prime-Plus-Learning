#include<iostream>
#include<string>
using namespace std;

class Person
{
private:
    string firstname;
    string lastname;
public:
    Person(string fn="none", string ln="none") : firstname(fn), lastname(ln) {}
    virtual ~Person() {}
    virtual void Show() const { cout << "First name: " << firstname << endl << "Last name: " << lastname << endl; }
};

class Gunslinger : virtual public Person
{
private:
    double drawtime;
    int notches;
public:
    Gunslinger(string fn="none", string ln="none", double dt=0.0, int n=0) : Person(fn, ln), drawtime(dt), notches(n) {}
    virtual ~Gunslinger() {}
    double draw() const { return drawtime; }    
    virtual void Show() const { Person::Show(); cout << "Draw time: " << drawtime << endl << "Notches: " << notches << endl; }
};

class PokerPlayer : virtual public Person
{
public:
    PokerPlayer(string fn="none", string ln="none") : Person(fn, ln) {}
    virtual ~PokerPlayer() {}
    int draw() const { return rand() % 52 + 1; }
    virtual void Show() const { Person::Show(); cout << "Draw: " << draw() << endl; }
};

class BadDude : public Gunslinger, public PokerPlayer
{
public:
    BadDude(string fn="none", string ln="none", double dt=0.0, int n=0) : Person(fn, ln), Gunslinger(fn, ln, dt, n), PokerPlayer(fn, ln) {}
    virtual ~BadDude() {}
    double Gdraw() const { return Gunslinger::draw(); }
    int Cdraw() const { return PokerPlayer::draw(); }
    virtual void Show() const { Gunslinger::Show(); cout << "Draw: " << Cdraw() << endl; }
};

int main()
{
    Person * p[4];

    p[0] = new Person("John", "Doe");
    p[1] = new Gunslinger("Jane", "Doe", 5.0, 3);
    p[2] = new PokerPlayer("Jim", "Doe");
    p[3] = new BadDude("Jack", "Doe", 4.0, 2);

    for (int i = 0; i < 4; i++)
    {
        p[i]->Show();
        cout << endl;
    }

    for (int i = 0; i < 4; i++)
        delete p[i];
    
    return 0;
}