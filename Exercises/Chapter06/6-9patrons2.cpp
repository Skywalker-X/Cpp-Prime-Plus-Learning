#include<iostream>
#include<string>
#include<fstream>
using namespace std;

const int Grand = 10000; 
struct Patron
{
    string name;
    double amount;
};

int main(){
    ifstream inFile;
    inFile.open("6-9.txt");

    int num;
    inFile>>num;
    inFile.get();

    Patron *patrons = new Patron [num];
    for (int i=0; i<num; i++){
        getline(inFile, patrons[i].name);
        inFile>>patrons[i].amount;
        inFile.get();
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

    inFile.close();

    return 0;
}
