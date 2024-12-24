#include<iostream>
#include "9-4-1np.h"

namespace SALES
{
    using namespace std;
    
    void setSales(Sales &s, const double ar[], int n)
    {
        s.max = 0;
        s.min = ar[0];
        double total = 0;
        for(int i=0; i<QUARTERS; i++)
            s.sales[i] = 0;

        for(int i=0; i<n; i++)
        {
            s.sales[i] = ar[i];
            total += ar[i];
            s.max = s.max>ar[i] ? s.max:ar[i];
            s.min = s.min<ar[i] ? s.min:ar[i];       
        }
        s.average = total/QUARTERS;
    }
    void setSales(Sales &s)
    {
        s.max = 0;
        double total = 0;

        cout<<"Enter sales for 4 seasons: ";
        for(int i=0; i<QUARTERS; i++)
        {
            cin>>s.sales[i];
            total += s.sales[i];
        }
        s.min = s.sales[0];
        for(int i=0; i<QUARTERS; i++)
        {
            s.max = s.max>s.sales[i] ? s.max:s.sales[i];
            s.min = s.min<s.sales[i] ? s.min:s.sales[i];
        }
        s.average = total/QUARTERS;
    }

    void showSales(const Sales &s)
    {
        for(int i=0; i<QUARTERS; i++)
            cout<<"Sales for season "<<i<<" : "<<s.sales[i]<<endl;
        cout<<"Average: "<<s.average<<endl;
        cout<<"Max: "<<s.max<<endl;
        cout<<"Min: "<<s.min<<endl;
    }
} 


