#include<iostream>
#include<string>

struct CandyBar
{
    std::string band;
    double weight;
    int calories;
};


int main(){
    using namespace std;

    CandyBar mocha = {"Mocha Munch", 2.3, 350};

    cout<<"Band: "<<mocha.band<<endl<<"Weight: "<<mocha.weight<<endl<<"Calories: "<<mocha.calories<<endl;

    return 0;
}