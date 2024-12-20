#include<iostream>

int factorial(int n)
{
    if(n==0)
        return 1;
    else 
        return n*factorial(n-1);
}

int main()
{
    int n;

    while((std::cin>>n) && n>=0)
        std::cout<<factorial(n)<<std::endl;
    
    return 0;
}