#include<iostream>
#include "10-4-1np.h"

namespace SALES
{
    using namespace std;

    Sales::Sales()
    {
        for(int i=0; i<QUARTERS; i++)
            sales[i] = 0;
        average = 0;
        max = 0;
        min = 0;
    }

    Sales::Sales(const double ar[], int n)
    {
        max = 0;
        min = ar[0];
        double total = 0;
        for(int i=0; i<QUARTERS; i++)
            sales[i] = 0;

        for(int i=0; i<n; i++)
        {
            sales[i] = ar[i];
            total += ar[i];
            max = max>ar[i] ? max:ar[i];
            min = min<ar[i] ? min:ar[i];       
        }
        average = total/QUARTERS;
    }
    
    void Sales::setSales()
    {
        max = 0;
        double total = 0;

        cout<<"Enter sales for 4 seasons: ";
        for(int i=0; i<QUARTERS; i++)
        {
            cin>>sales[i];
            total += sales[i];
        }
        min = sales[0];
        for(int i=0; i<QUARTERS; i++)
        {
            max = max>sales[i] ? max:sales[i];
            min = min<sales[i] ? min:sales[i];
        }
        average = total/QUARTERS;
    }

    void Sales::showSales() const
    {
        for(int i=0; i<QUARTERS; i++)
            cout<<"Sales for season "<<i<<" : "<<sales[i]<<endl;
        cout<<"Average: "<<average<<endl;
        cout<<"Max: "<<max<<endl;
        cout<<"Min: "<<min<<endl;
    }
} 


