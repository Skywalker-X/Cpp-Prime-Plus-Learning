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

    CandyBar mocha[3] = {
        {"Mocha Munch", 2.3, 350},
        {"xxx", 3.3, 450},
        {"sss", 5.3, 500}
    };

    cout<<"Band: "<<mocha[0].band<<endl<<"Weight: "<<mocha[0].weight<<endl<<"Calories: "<<mocha[0].calories<<endl;
    cout<<"Band: "<<mocha[1].band<<endl<<"Weight: "<<mocha[1].weight<<endl<<"Calories: "<<mocha[1].calories<<endl;
    cout<<"Band: "<<mocha[2].band<<endl<<"Weight: "<<mocha[2].weight<<endl<<"Calories: "<<mocha[2].calories<<endl;

    return 0;
}