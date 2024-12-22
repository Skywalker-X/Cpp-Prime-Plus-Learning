#include<iostream>
#include<cstring>

template <typename T>
T maxn(const T arr[], int n)
{
    auto i = arr[0];
    for(int j=1; j<n; j++)
        i = i>arr[j] ? i:arr[j];
    return i;
}



template <> const char* maxn<const char*> (const char* const arr[], int n)
{
    const char* longest = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (strlen(arr[i]) > strlen(longest))
        {
            longest = arr[i];
        }
    }
    return longest;
}

int main()
{
    using namespace std;
    double darr[4] = {1.1, 2.2, 3.3, 4.4};
    int iarr[6] = {1, 2, 3, 4, 5, 6};
    const char* charr[4] = {"short", "longer", "the longest string in the array", "tiny"};
    cout<<maxn(darr,4)<<endl<<maxn(iarr,6)<<endl;
    cout<<maxn(charr,4)<<endl;
    return 0;
}