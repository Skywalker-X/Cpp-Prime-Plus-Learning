#include <iostream>
#include <string>

struct Pizza
{
    std::string company;
    double diameter;
    double weight;
};

int main() {
    using namespace std;

    Pizza *pizza = new Pizza;

    cout << "Enter the diameter of pizza: ";
    cin >> pizza->diameter;
    cout << "Enter the weight of pizza: ";
    cin >> pizza->weight;
    cin.get();
    cout << "Enter the pizza company: ";
    getline(cin, pizza->company);

    cout<< "Company: " << pizza->company << endl << "Diameter: " << pizza->diameter << endl << "Weight: " << pizza->weight << endl;

    return 0;
}