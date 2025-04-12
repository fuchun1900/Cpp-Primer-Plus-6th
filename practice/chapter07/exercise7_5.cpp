//
// Created by fuchun on 2025/4/12.
//
# include <iostream>

unsigned long factorial(int n);

int main()
{
    using namespace std;
    int n;
    cout << "Enter a positive integer: ";
    while (cin >> n && n >= 0)
    {
        cout << n << "! = " << factorial(n) << endl;
        cout << "Enter a positive integer (q to quit): ";
    }
}

unsigned long factorial(int n)
{
    if(n > 1)
        return n * factorial(n - 1);
    return 1;
}