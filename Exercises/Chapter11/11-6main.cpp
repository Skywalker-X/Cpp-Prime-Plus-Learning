#include <iostream>
#include "11-6stonewt.h"

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    Stonewt arr[6] = {
        Stonewt(275),
        Stonewt(21, 8),
        Stonewt(15, 0)
    };

    double lbs;
    for (int i = 3; i < 6; ++i)
    {
        cout << "Enter weight in pounds for element " << i + 1 << ": ";
        cin >> lbs;
        arr[i] = Stonewt(lbs);
    }

    Stonewt min = arr[0];
    Stonewt max = arr[0];
    Stonewt eleven_stone = Stonewt(11 * 14);
    int count = 0;

    for (int i = 0; i < 6; ++i)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] >= eleven_stone)
            count++;
    }

    cout << "Minimum weight: ";
    min.show_lbs();
    cout << "Maximum weight: ";
    max.show_lbs();
    cout << "Number of elements >= 11 stones: " << count << endl;

    return 0;
}