#include <iostream>
#include <cctype>
#include <string>
int main(){
    using namespace std;
    string word;
    int vowels=0, cons=0, total=0;

    cout<<"Enter words (q to quit): \n";

    while((cin>>word) && word != "q")
    {
        total++;
        
        if(isalpha(word[0]))
        {
            switch (word[0])
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowels++;
                    break;
                default:
                    cons++;
                    break;
            }
        }
    }

    cout<<vowels<<" words beginning with vowels.\n";
    cout<<cons<<" words beginning with consonants.\n";
    cout<<total-vowels-cons<<" others.";

    return 0;
}