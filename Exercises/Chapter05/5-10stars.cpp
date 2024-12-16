#include<iostream>
int main(){
    using namespace std;
    int num;
    cout<<"Enter number of rows: ";
    cin>>num;

    for (int i=0; i<num; i++){
        for (int j=0; j<num-1-i; j++)
            cout<<".";
        for (int j=0; j<i+1; j++)
            cout<<"*";
        cout<<endl;
    }

    return 0;
}