#include<iostream>
#include<string>
int main(){
    using namespace std;
    string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int sales[12];
    int sum = 0;

    for (int i=0; i<12; i++){
        cout<<"Sales for "<<months[i]<<": ";
        cin>>sales[i];
        sum += sales[i];
    }

    cout<<"Sales for total year is "<<sum<<endl;

    for (int i=0; i<12; i++)
        cout<<"Sales for "<<months[i]<<" is "<<sales[i]<<endl;

    return 0;
    
}