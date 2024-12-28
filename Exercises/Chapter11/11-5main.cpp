#include <iostream>
#include "11-5stonewt.h"

int main()
{
    using std::cout;
    using std::endl;

    Stonewt st1(275);
    Stonewt st2(21, 8);
    Stonewt st3;

    cout << "st1: " << st1 << endl;
    cout << "st2: " << st2 << endl;

    st3 = st1 + st2;
    cout << "st1 + st2: " << st3 << endl;

    st3 = st1 - st2;
    cout << "st1 - st2: " << st3 << endl;

    st3 = st1 * 2.5;
    cout << "st1 * 2.5: " << st3 << endl;

    st1.set_mode(Stonewt::STONE);
    cout << "st1 in stone mode: " << st1 << endl;

    st1.set_mode(Stonewt::INT_LBS);
    cout << "st1 in integer pounds mode: " << st1 << endl;

    st1.set_mode(Stonewt::FLOAT_LBS);
    cout << "st1 in float pounds mode: " << st1 << endl;

    return 0;
}