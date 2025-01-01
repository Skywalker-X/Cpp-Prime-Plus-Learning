#include<iostream>
#include<cstring>
using namespace std;

class Cow
{
private:
    char name[20];
    char *hobby;
    double weight;
public:
    Cow();
    Cow(const char* nm, const char * ho, double wt);
    Cow(const Cow & c);
    ~Cow();
    Cow & operator=(const Cow & c);
    void ShowCow() const;
};

Cow::Cow()
{
    name[0] = '\0';
    hobby = NULL;
    weight = 0;
}

Cow::Cow(const char* nm, const char * ho, double wt)
{
    strncpy(name, nm, 19);
    name[19] = '\0';
    hobby = new char[strlen(ho)+1];
    strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow & c)
{
    strncpy(name, c.name, 19);
    name[19] = '\0';
    if (c.hobby) 
    {
        hobby = new char[strlen(c.hobby) + 1];
        strcpy(hobby, c.hobby);
    } 
    else 
    {
        hobby = nullptr;
    }
    weight = c.weight;
}

Cow::~Cow()
{
    delete [] hobby;
}

Cow & Cow::operator=(const Cow & c)
{
    if(this == &c)
        return *this;

    delete [] hobby;

    strncpy(name, c.name, 19);
    name[19] = '\0';

    if (c.hobby) 
    {
        hobby = new char[strlen(c.hobby) + 1];
        strcpy(hobby, c.hobby);
    } 
    else 
    {
        hobby = nullptr;
    }
    weight = c.weight;
    return *this;
}

void Cow::ShowCow() const {
    cout << "Name: " << name << endl;
    cout << "Hobby: " << (hobby ? hobby : "None") << endl;
    cout << "Weight: " << weight << " kg" << endl;
}

int main() {
    Cow cow1;
    cout << "Default Cow:" << endl;
    cow1.ShowCow();

    Cow cow2("Bessie", "Grazing", 450.5);
    cout << "\nCow with Parameters:" << endl;
    cow2.ShowCow();

    Cow cow3(cow2);
    cout << "\nCopied Cow:" << endl;
    cow3.ShowCow();

    Cow cow4;
    cow4 = cow2;
    cout << "\nAssigned Cow:" << endl;
    cow4.ShowCow();

    return 0;
}