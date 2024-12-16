#include <iostream>

int main() {
    using namespace std;

    const double km2mile = 0.6214;
    const double gallon2litre = 3.875;

    double eucomsuption;
    cout << "Oil comsuption in European standard: ";
    cin >> eucomsuption;

    double uscomsuption = (100 * km2mile) / (eucomsuption/gallon2litre);
    cout << "Oil comsuption in US standard is " << uscomsuption << " Miles/Gallon (mpg)." << endl;  

    return 0;
}