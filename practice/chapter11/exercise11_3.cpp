
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype
#include "vect.h"
int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));     // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    int test = 0;
    double max;
    double min;
    double sum;
    max = min = sum = 0.0;
    cout << "Random Walk Test Program\n";
    cout << "Enter the number of tests (0 to quit): ";
    while (!(cin >> test) || test <= 0)
    {
        cout << "Please rertry!\n";
    }
    cout << "Enter target distance (q to quit): ";
    while (!(cin >> target) || target <= 0)
    {
        cout << "Please enter a positive target distance.\n";
        cout << "Enter target distance (q to quit): ";
    }
    cout <<"Enter the stpe length (positive number): ";
     while (!(cin >> dstep) || dstep <= 0)
    {
        cout << "Please enter a positive target distance.\n";
        cout << "Enter stpe length (q to quit): ";
    }
    cout << "Target distance: " << target << endl;
    cout << "Enter step length: ";
    int count = 0;
    while (test--)
    {
        result.reset(0.0, 0.0);
        direction = 0.0;
        steps = 0;
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        cout << "After " << steps << " steps, the subject "
            "has the following location:\n";
        cout << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = "
            << result.magval()/steps << endl;
        sum += steps;
        count++;
        if (steps > max)
            max = steps;
        if (steps < min || min == 0.0)
            min = steps;
        cout << "-----------------------------------------\n"; 
    }
    cout << "After " << count << " tests, the results are:\n";
    cout << "Maximum steps: " << max << endl;
    cout << "Minimum steps: " << min << endl;
    cout << "Average steps: " << sum / count << endl;
    cout << "-----------------------------------------\n";
    cout << "Bye!\n";
    return 0;
}
    

