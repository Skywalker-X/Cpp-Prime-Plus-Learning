#include<iostream>
int main(){
    using namespace std;
    double daphne=100, cleo=100;
    int year;
    for (year=0; daphne>=cleo; year++){
        daphne += 10;
        cleo *= 1.05;
    }
    cout<<"Year: "<<year<<endl;
    cout<<"Daphne: "<<daphne<<endl;
    cout<<"Cleo: "<<cleo<<endl;
    
    return 0;
}