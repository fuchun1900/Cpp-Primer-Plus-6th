//
// Created by fuchun  on 2025/4/12.
//
#include <iostream>
#include <cctype>

void display(const float * , int);
int read(float * , int);
float average(const float * , int);

int main()
{
    using namespace std;
    const int Size = 10;
    float golf[Size] = {0};
    int readnumber = 0;
    cout << "Please enter your 10 golf scores,press 'q' to quit .\n";
    cout << "You can enter up to 10 scores.\n";
    readnumber = read(golf, Size);
    display(golf, readnumber);
    // cin.get();
    // cin.get();
    return 0;
}

int read(float * arr, int n)
{
    using namespace std;
    int readnumber = 0;  
    while (readnumber < n && cin >> arr[readnumber])
    {
        readnumber++;
        if (readnumber == n)
            break;
        if(cin.get() == '\n')
            cout << "You can enter up to 10 scores.\n";
    }
    return readnumber;
}

float average(const float * arr, int size)
{
    using namespace std;
    float sum = 0.0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum / size;
}

void display(const float * arr , int size)
{
    using namespace std;
    cout << "Your golf scores are:\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Average score: " << average(arr, size) << endl;
}

