#include <iostream>
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tree = 3;
    int guess = 3.9832;
    int debt = 7.2E12;
    cout << "tree = " << tree << endl;
    cout << "guess = " << guess << endl;
    cout << "debt = " << debt << endl;
    return 0;
}
// results:
// 3-13assign.cpp: In function 'int main()':
// 3-13assign.cpp:8:16: warning: overflow in implicit constant conversion [-Woverflow]
//      int debt = 7.2E12;  // result not defined in C++        
//                 ^~~~~~
// tree = 3.000000
// guess = 3
// debt = 2147483647