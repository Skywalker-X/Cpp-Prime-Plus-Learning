#include<iostream>
int main(){
    using namespace std;
    char ch;
    bool flag = true;

    cout << "Please enter one of the following choice: \n";
    cout << "c) carnivore \t p) pianist\n"
         << "t) tree \t g) game\n";
    // cin>>ch;

    while( flag && (ch=cin.get()) ){
        switch (ch)
        {
            case 'c':
                cout<<"carnivore";
                flag = false;
                break;
            case 'p':
                cout<<"panist";
                flag = false;
                break;
            case 't':
                cout<<"tree";
                flag = false;
                break;
            case 'g':
                cout<<"game";
                flag = false;
                break;
            default:
                cout<<"please enter a c, p, t, or g: ";
                break;
        }
    }
    
    return 0;
}