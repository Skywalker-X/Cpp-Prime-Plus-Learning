#include<iostream>
using namespace std;

int Fill_array(double *arr, int n)
{
    int count = 0;
    while ((cin>>arr[count]) && count<n)
        count++;  
    return count;
}

void Show_array(const double *arr, int n)
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void Reverse_array(double *arr, int n)
{
    for(int i=0; i<n/2; i++)
    {
        double tmp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = tmp;
    }
}

int main()
{
    double arr[10];
    int n = Fill_array(arr, 10);
    Show_array(arr, n);
    Reverse_array(arr, n);
    Show_array(arr, n);
    Reverse_array(arr+1, n-2);
    Show_array(arr, n);
    return 0;
}