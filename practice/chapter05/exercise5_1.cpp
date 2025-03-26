// Create by fuchun on 2025-03-27
#include <iostream>

int main()
{
    using namespace std;
    int min = 0;
    int max = 0;
    int sum = 0;

    cout << "Enter the minimum number: ";
    cin >> min;
    cout << "Enter the maximum number: ";
    cin >> max;

    for (size_t i = min; i <= max; i++)
    {
        sum += i;
    }
    cout << "The sum of all the numbers between " << min << " and " << max << " is " << sum << endl;

    return 0;
    
}

