#include<iostream>
#include<cctype>
int main(){
    using namespace std;
    const int SIZE = 10;
    double donation[10];
    int i=0, n=0;
    double avg, sum = 0;

    while((i<SIZE) && (cin>>donation[i])){
        sum += donation[i];
        i++;
    }

    avg = sum / i;
    for(int j=0; j<=i; j++)
        n += (donation[j]>avg) ? 1 : 0;
    
    cout<<"Avg: "<<avg<<endl;
    cout<<n<<" numbers greater than avg.\n";

    return 0;
}