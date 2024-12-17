#include<iostream>
#include<string>
using namespace std;

const int Grand = 10000; 
struct Patron
{
    string name;
    double amount;
};

int main(){
    int num;
    cout<<"Numbers: ";
    cin>>num;
    cin.get();

    Patron *patrons = new Patron [num];
    for (int i=0; i<num; i++){
        cout<<"Name: ";
        getline(cin, patrons[i].name);
        cout<<"Amount: ";
        cin>>patrons[i].amount;
        cin.get();
    }


    int count1=0, count2=0;
    cout<<"Grand Patrons: \n";
    for (int i=0; i<num; i++){
        if(patrons[i].amount>Grand){
            count1++;
            cout<<patrons[i].name<<endl;
        }
    }
    if(count1 == 0) cout<<"none\n";

    cout<<"Patrons: \n";
    for (int i=0; i<num; i++){
        if(patrons[i].amount <= Grand){
            count2++;
            cout<<patrons[i].name<<endl;
        }
    }
    if(count2 == 0) cout<<"none\n";

    return 0;
}
