#include<iostream>
#include<cctype>
#include<string>
using namespace std;

void strupper(string & str)
{
    int i = 0;
    while (str[i])
    {
        str[i] = toupper(str[i]);
        i++;
    }
}

int main()
{
    string str;
    cout<<"Enter a string (q to quit): ";
    getline(cin, str);
    while ( str != "q")
    {
        strupper(str);
        cout<<str<<endl;
        cout<<"Next string (q to quit): ";
        getline(cin, str);
    }
    cout<<"Bye.\n";
    return 0;
}