#include<iostream>
#include<string>
using namespace std;

const int ArSize = 10;

void strcount(const string str);

int main()
{
    string input;

    cout<<"Enter a line: \n";
    getline(cin, input);
    while(input != "")
    {
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        getline(cin, input);
    }
    cout << "Bye\n";
    return 0;
}

void strcount(const string str)
{
    using namespace std;
    static int total = 0;
    int count = str.size();

    total += count;

    cout << "\"" << str <<"\" contains ";
    cout << count << " characters\n";
    cout << total << " characters total\n";
}