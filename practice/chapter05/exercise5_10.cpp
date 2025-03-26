// Create by fuchun on 2025/3/25
#include <iostream>

int main()
{
    using namespace std;
    int rows;
    cout << "Enter number of rows:";
    cin >> rows;
    for (size_t i = 1; i <= rows; i++)
    {
        for (int j = rows - i , k = 1; k <= rows; j--,k++)
        {
            if (j > 0)
            {
                cout << (".") << '\t';
            }
            else
            {
                cout << ("*") << '\t';
            }
        }
        cout << endl;
    }
    return 0;
}
