#include<iostream>
#include<string>
int main(){
    using namespace std;
    string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int sales[3][12];
    int sum = 0;

    for (int j=0; j<3; j++){
        for (int i=0; i<12; i++){
            cout<<"Sales for "<<months[i]<<" in the "<<j+1<<"-th year: ";
            cin>>sales[j][i];
            sum += sales[j][i];
        }
    }

    cout<<"Sales for total year is "<<sum<<endl;

    for (int j=0; j<3; j++){
        for (int i=0; i<12; i++)
            cout<<"Sales for "<<months[i]<<" in the "<<j+1<<"-th year is "<<sales[j][i]<<endl;
    }
     
    return 0;
}