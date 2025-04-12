// arrfun3.cpp -- array functions and const
//
// Modified by fuchun on 2025/4/12.
//
#include <iostream>
const int Max = 5;  

// function prototypes
double * fill_array(double * start, double * end);
void show_array(const double ar[], const double * end);  // don't change data
void revalue(double r, double * start, double * end);

int main()
{
    using namespace std;
    double properties[Max];

    double  * end = fill_array(properties, properties + Max);
    show_array(properties, end);
    if (end != properties )
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))    // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
           cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, properties, end);
        show_array(properties, end);
    }
    cout << "Done.\n";
    // cin.get();
    // cin.get();
    return 0;
}

double * fill_array(double * start, double * end)
{
    using namespace std;
    double temp;
    double * ptr = nullptr;
    int i = 0;
    for (ptr = start ; start != end; start++ ,i++)
    {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin)    // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
           cout << "Bad input; input process terminated.\n";
           break;
        }
        else if (temp < 0)     // signal to terminate
            break;
        *start = temp;
    }
    return start;
}

// the following function can use, but not alter,
// the array whose address is ar
void show_array(const double ar[], const double * end)
{
    using namespace std;
    int i = 1;
    while (ar != end)
    { 
        cout <<"Value # " << i << " is " << *ar << endl;
        i++;
        ar++;
    }

}

// multiplies each element of ar[] by r
void revalue(double r, double * start, double * end)
{
    while (start != end)
    { 
       *start *= r;
        start++;
    }
}
