#include<iostream>
#include<cstdlib>
#include<ctime>
#include"vector.h"

int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    int N;
    unsigned long max_steps = 0;
    unsigned long min_steps = ULONG_MAX;
    unsigned long total_steps = 0;

    cout << "Enter number of tests: ";
    cin >> N;
    cout<<"Enter target distance (q to quit): ";
    while(cin>>target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;

        for (int i = 0; i < N; i++)
        {
            while (result.magval() < target)
            {
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::POL);
                result = result + step;
                steps++;
            }
            if (steps > max_steps)
                max_steps = steps;
            if (steps < min_steps)
                min_steps = steps;
            total_steps += steps;

            steps = 0;
            result.reset(0.0, 0.0);
        }

        cout << "After " << N << " tests:\n";
        cout << "Maximum steps: " << max_steps << endl;
        cout << "Minimum steps: " << min_steps << endl;
        cout << "Average steps: " << total_steps / N << endl;

        max_steps = 0;
        min_steps = ULONG_MAX;
        total_steps = 0;

        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    cin.get();
    return 0; 
}