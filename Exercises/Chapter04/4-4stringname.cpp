#include<iostream>
#include<string>
int main(){
    using namespace std;

    string firstname, lastname, name;

    cout << "Enter your first name: ";
    getline(cin, firstname);
    cout << "Enter your last name: ";
    getline(cin, lastname);

    name = lastname + ", " + firstname;

    cout << "Here's the information in a single string: " << name << endl;

    return 0;
}