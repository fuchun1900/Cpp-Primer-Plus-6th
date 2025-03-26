// Create by fuchun on 2021-07-28
#include <iostream>
#include <array>

const int ArSize = 101;
int main()
{
    using namespace std;
    array<long double, ArSize> factorials = {1 ,1};
    for (size_t i = 2; i < ArSize; i++)
    {
        factorials[i] = i * factorials[i - 1];
    }
    for (size_t i = 0; i < ArSize; i++)
    {
        cout << i << "! = " << factorials[i] << endl;
    }
    
    return 0;
}
