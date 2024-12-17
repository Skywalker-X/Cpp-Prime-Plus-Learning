#include<iostream>
#include<fstream>
int main(){
    using namespace std;
    ifstream inFile;
    int count=0;
    char ch;

    inFile.open("test.txt");
    while((ch=inFile.get())!=EOF)
        count++;
    inFile.close();

    cout<<"Count characters: "<<count<<endl;

    return 0;
}