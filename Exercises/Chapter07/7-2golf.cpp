#include<iostream>
using namespace std;

const int SIZE = 10;

int input(double *score)
{
    int count = 0;
    while((cin>>score[count]) && count<SIZE)
    {
        if(score[count]<0)
            break;
        
        count++;
    }
    return count;
}

void show(const double *score, int n)
{
    for (int i=0; i<n; i++)
        cout<<score[i]<<" ";
    cout<<endl;
}

double avg(const double score[], int n)
{
    double sum = 0;
    for (int i=0; i<n; i++)
        sum += score[i];
    return sum/n;
}

int main()
{
    double score[SIZE];
    int n = input(score);
    show(score, n);
    cout<<"Avg: "<<avg(score,n);
    return 0;
}