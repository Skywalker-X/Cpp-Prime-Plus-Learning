#include<iostream>
#include<string>
int main()
{
    using namespace std;
    const int ArSize = 20;
    // char name[ArSize];
    // char dessert[ArSize];
    string name, dessert;

    cout << "Enter your name:\n";
    // cin.getline(name, ArSize);
    getline(cin, name);
    cout << "Enter your favorite dessert:\n";
    // cin.getline(dessert, ArSize);
    getline(cin, dessert);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    return 0; 
}