#include "/home/DEV/C++_Project/Cpp-Primer-Plus-6th/bookcodes/chapter11/vect.h"
#include "/home/DEV/C++_Project/Cpp-Primer-Plus-6th/bookcodes/chapter11/vect.cpp"
#include <fstream>

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
    ofstream fout;
    fout.setf(ios::fixed, ios::floatfield);
    fout.precision(2);
    const char * file = "randwalk.txt";
    fout.open(file);
    // Check if the file opened successfully
    if (!fout)
    {
        cerr << "Error opening file " << file << endl;
        return 1; // Exit with an error code
    }
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        fout << "Target distance: " << target << ", Step length: " << dstep << endl;

        while (result.magval() < target)
        {
            fout << "Step " << steps << ": ";
            fout << "Current position: " << result << endl;
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        fout << "Step " << steps << ": ";
        fout << "Current position: " << result << endl;
        fout << "After " << steps << " steps, the subject "
            "has the following location:\n";
        fout << result << endl;
        result.polar_mode();
        fout << " or\n" << result << endl;
        fout << "Average outward distance per step = "
            << result.magval()/steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
/* keep window open
    cin.clear();
    while (cin.get() != '\n')
        continue;
    cin.get();
*/
    return 0;
}



