#include<iostream>
const int strsize = 40;
struct bop {
    char fullname[strsize]; // real name
    char title[strsize];    // job title
    char bopname[strsize];  // secret BOP name
    int preference;         // 0 = fullname, 1 = title, 2 = bopname
};
int main(){
    using namespace std;
    char ch;
    const bop bops[5] = {
        {"Wimp Macho",   "xxxxx",             "xxxxx",  0},
        {"Raki Rhodes",  "Junior Programmer", "xxxxx",  1},
        {"Celia Laiter", "xxxxx",             "MIPS",   2},
        {"Hoppy Hipman", "Analyst Trainee",   "xxxxx",  1},
        {"Pat Hand",     "xxxxx",             "LOOPY",  2}
    };

    cout << "Benevolent order of Programmers report.\n";
    cout << "a. display by name     b. display by title\n"
         << "c. display by bopname  d. display by preference\n"
         << "q. quit" << endl;
    cout << "Enter your choice: ";

    while((ch=cin.get())!='q'){
        for (int i=0; i < 5; ++i) {
            switch (ch) {
                case 'a':
                    cout << bops[i].fullname << "\n";
                    break;
                case 'b':
                    cout << bops[i].title << "\n";
                    break;
                case 'c':
                    cout << bops[i].bopname << "\n";
                    break;
                case 'd':
                    if(bops[i].preference==0)
                        cout << bops[i].fullname << "\n";
                    else if(bops[i].preference==1)
                        cout << bops[i].title << "\n";
                    else
                        cout << bops[i].bopname << "\n";
                    break;
                default:
                    break;
            }
        }
        cin.get();
        cout<<"Next choice: ";
    }

    cout<<"Bye!\n";

    return 0;
}