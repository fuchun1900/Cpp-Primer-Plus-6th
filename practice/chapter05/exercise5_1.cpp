// Create by fuchun on 2025-03-27
// modify by fuchun on 2025-04-05
#include <iostream>
#include <cmath>

int main()
{
    using namespace std;
    int a, b, total = 0;
    cout << "Enter two integers: ";
    cin >> a >> b;
    int start = a > b ? b : a;
    int step = abs(a - b);
    while (step-- >= 0)
    {
        total += start;
        start++;
    }
    
    cout << "The sum of " << a << " between " << b << " is " << total << endl;

    return  0;
}

