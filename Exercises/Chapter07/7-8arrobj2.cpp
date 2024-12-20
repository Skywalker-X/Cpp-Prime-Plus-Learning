#include <iostream>
#include <array>
#include <string>
const int Seasons = 4;
const char *Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};

struct Expense
{
    double expense;
};

void fill(Expense *pa);
void show(const Expense *da);

int main()
{
    Expense expenses[Seasons];
    fill(expenses);
    show(expenses);
    return 0;
}

void fill(Expense *pa)
{
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> (pa+i)->expense;
    }
}

void show(const Expense *da)
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << Snames[i] << ": $" << (da+i)->expense << '\n';
        total += (da+i)->expense;
    }
    std::cout << "Total: $" << total << '\n';
}