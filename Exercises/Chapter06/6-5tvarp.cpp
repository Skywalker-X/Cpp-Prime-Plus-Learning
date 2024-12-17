#include<iostream>
int main(){
    using namespace std;
    double tvarp, tax;
    
    cout<<"Salary: ";
    
    while((cin>>tvarp) && (tvarp>=0)){
        if(tvarp<=5000)
            tax = 0;
        else if(tvarp<=15000)
            tax = (tvarp - 5000)*0.1;
        else if(tvarp<=35000)
            tax = 1000 + (tvarp-15000)*0.15;
        else
            tax = 1000 + 3000 + (tvarp-35000)*0.2;

        cout<<"Tax: "<<tax<<endl;
    }
    
    return 0;
}