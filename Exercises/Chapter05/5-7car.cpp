#include<iostream>
#include<string>

struct Car
{
    std::string producer;
    int year;
};


int main(){
    using namespace std;
    int num;
    cout<<"How many cars do you wish to catalog? ";
    cin>>num;
    Car *cars = new Car [num];
    cin.get();

    for (int i=0; i<num; i++){
        cout<<"Car #"<<i+1<<":\n";
        cout<<"Please enter the make: ";
        getline(cin, cars[i].producer);
        cout<<"Please enter the year made: ";
        cin>>cars[i].year;
        cin.get();
    }

    cout<<"Here is your collection: \n";
    for (int i=0; i<num; i++){
        cout<<cars[i].year<<"\t"<<cars[i].producer<<endl;
    }

    return 0;
}