#include<iostream>
#include "9-4-1np.h"

int main(){
    using namespace std;
    using namespace SALES;

    double arr[QUARTERS] = {1.2, 3.4, 5.6, 7.8};
    Sales s1, s2;
    setSales(s1, arr, QUARTERS);
    showSales(s1);
    setSales(s2);
    showSales(s2);
    return 0;
}