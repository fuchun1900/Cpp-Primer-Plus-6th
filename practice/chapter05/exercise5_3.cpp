// Create by fuchun on 2025-03-27
#include <iostream>
int main()
{
    using namespace std;
    double num = 0.0;
    double sum = 0.0;
    cout << "Enter a number: ";
    do
    {
        cin >> num;
        sum += num;
    } while (num != 0);
    cout << "The sum of the numbers you entered is " << sum << endl;

    return 0;
}
