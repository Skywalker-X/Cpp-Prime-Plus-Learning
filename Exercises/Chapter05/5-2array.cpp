#include <iostream>
#include<array>
const int ArSize = 101;
int main()
{   
    std::array<long double, ArSize> factorials;
    // long long factorials[ArSize];
    factorials[1] = factorials[0] = 1;
    for (int i = 2; i < ArSize; i++)
        factorials[i] = i * factorials[i-1];
    for (int i = 0; i < ArSize; i++)
        std::cout << i << "! = " << factorials[i] << std::endl;
    return 0;
}