#include<iostream>
#include"14-1studentc.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student & sa, int n)
{
    cout << "Enter student's name: ";
    getline(cin, sa);
    cout << "Enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; i++)
        cin >> sa[i];
    while (cin.get() != '\n')
        continue;
}

const int pupils = 3;
const int quizzes = 5;

int main()
{
    Student ada[pupils] = {Student(quizzes), Student(quizzes), Student(quizzes)};

    for (int i = 0; i < pupils; i++)
        set(ada[i], quizzes);
    cout << "\nStudent List:\n";
    for (int i = 0; i < pupils; i++)
        cout << ada[i].Name() << endl;
    cout << "\nResults:";
    for (int i = 0; i < pupils; i++)
    {
        cout << endl << ada[i];
        cout << "average: " << ada[i].Average() << endl;
    }
    cout << "Done.\n";
    return 0;
}