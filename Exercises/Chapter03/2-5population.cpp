#include <iostream>

int main(){
    using namespace std;
    long long population_world, population_US;
    
    cout << "Enter the world's population: ";
    cin >> population_world;
    cout << "Enter the population of the US: ";
    cin >> population_US;

    double rate = double(population_US)/population_world;
    cout << "The population of the US is " << rate * 100
         << "% of the world population." << endl;

    return 0;
}
