#include<iostream>
#include<cstring>
int main(){
    using namespace std;

    char firstname[20];
    char lastname[20];
    char name[40];

    cout << "Enter your first name: ";
    cin.getline(firstname, 20);

    cout << "Enter your last name: ";
    cin.getline(lastname, 20);    

    strcpy(name, lastname);
    strcat(name, ", ");
    strcat(name, firstname);

    cout << "Here's the information in a single string: " << name << endl;

    return 0;
}