#include<iostream>
int main(){
    using namespace std;
    int height;
    const int foot2inch = 12;

    cout<<"Input height in inch: ";
    cin>>height;
    cout<<"The height is "<<height/foot2inch<<" foot "<<height%foot2inch<<" inch.";

    return 0;
}