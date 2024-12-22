#include<iostream>

template <typename T>
T max5(const T arr[])
{
    auto i = arr[0];
    for(int j=1; j<5; j++)
        i = i>arr[j] ? i:arr[j];
    return i;
}

int main()
{
    using namespace std;
    double darr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int iarr[5] = {1, 2, 3, 4, 5};
    cout<<max5(darr)<<endl<<max5(iarr)<<endl;
    return 0;
}