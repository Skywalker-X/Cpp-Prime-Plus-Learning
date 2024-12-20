#include<iostream>
#include<cstring>
using namespace std;
const int SLEN = 30;
struct student {
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n)
{
    int count = 0;
    for (int i = 0; i < n; ++i) {
        cout << "Enter full name: ";
        cin.getline(pa[i].fullname, SLEN);

        if (strlen(pa[i].fullname) == 0)
            break;

        cout << "Enter hobby: ";
        cin.getline(pa[i].hobby, SLEN);

        cout << "Enter oop level: ";
        cin >> pa[i].ooplevel;
        cin.get();

        ++count;
    }

    return count;
}

void display1(student st)
{
    cout<<"Name 1: "<<st.fullname<<endl;
    cout<<"Hobby 1: "<<st.hobby<<endl;
    cout<<"Ooplevel 1: "<<st.ooplevel<<endl;
}

void display2(const student *ps)
{
    cout<<"Name 2: "<<ps->fullname<<endl;
    cout<<"Hobby 2: "<<ps->hobby<<endl;
    cout<<"Ooplevel 2: "<<ps->ooplevel<<endl;
}

void display3(const student pa[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout<<"Name 3: "<<pa[i].fullname<<endl;
        cout<<"Hobby 3: "<<pa[i].hobby<<endl;
        cout<<"Ooplevel 3: "<<pa[i].ooplevel<<endl;
    }
}

int main()
{
    cout<<"Enter class size: ";
    int class_size;
    cin>>class_size;
    while (cin.get() != '\n')
        continue;
    
    student *ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i=0; i<entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    cout<<"Done\n";
    return 0;
}