#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<functional>

const int LIM = 6;

void show(double v)
{
    std::cout.width(6);
    std::cout<<v<<" ";
}

int main()
{
    using namespace std;
    double arr1[LIM] = {28, 29, 30, 35, 38, 59};
    double arr2[LIM] = {63, 65, 69, 75, 80, 99};
    vector<double> gr8(arr1, arr1+LIM);
    vector<double> m8(arr2, arr2+LIM);

    cout.setf(ios_base::fixed);
    cout.precision(1);
    cout<<"gr8:\t";
    for_each(gr8.begin(), gr8.end(), show);
    cout<<endl;
    cout<<"m8:\t";
    for_each(m8.begin(), m8.end(), show);
    cout<<endl;

    vector<double> sum(LIM);
    transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(), plus<double>());
    cout<<"sum:\t";
    for_each(sum.begin(), sum.end(), show);
    cout<<endl;

    vector<double> prod(LIM);
    transform(gr8.begin(), gr8.end(), prod.begin(), bind1st(multiplies<double>(), 2.5));
    cout<<"prod:\t";
    for_each(prod.begin(), prod.end(), show);
    cout<<endl;

    return 0;
}