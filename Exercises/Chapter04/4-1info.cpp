#include<iostream>
#include<string>
int main(){
    using namespace std;
    string firstname, lastname;
    char grade;
    int age;

    cout<<"What is your first name? ";
    getline(cin, firstname);
    cout<<"What is your last name? ";
    getline(cin, lastname);
    cout<<"What letter grade do you deserve? ";
    cin>>grade;
    grade += 1;
    cout<<"What is your age? ";
    cin>>age;

    cout<<"Name: "<<lastname<<", "<<firstname<<endl;
    cout<<"Grade: "<<grade<<endl;
    cout<<"Age: "<<age<<endl;

    return 0;
}