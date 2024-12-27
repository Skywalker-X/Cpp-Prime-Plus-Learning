#include<iostream>
#include "10-4-1np.h"

int main(){
    using namespace std;
    using namespace SALES;

    double arr[QUARTERS] = {1.2, 3.4, 5.6, 7.8};
    Sales s1(arr, QUARTERS), s2;
    s1.showSales();
    s2.setSales();
    s2.showSales();
    return 0;
}