//
// Created by fuchun on 2025/4/12.
//

#include <iostream>

int Fill_array(double * arr, int n);
void Show_array(const double * arr, int n);
void Reverse_array(double * arr, int n);

int main()
{
    using namespace std;

    cout << "Please the capacity of array:\n";
    int capacity = 0;
    cin >> capacity;
    double * arr = new double[capacity];
    int size = Fill_array(arr, capacity);
    if (size > 0)
    {
        Show_array(arr, size);
        Reverse_array(arr, size);
        Show_array(arr, size);
    }
    else
    {
        cout << "No numbers entered.\n";
    }
    
       delete [] arr;
}
int Fill_array(double * arr, int n)
{
    using namespace std;
    cout << "Please enter the numbers of array (q to quit):\n";
    double input = 0;
    int size = 0;
    
    for (int i = 0; i < n  && cin >> input ; i++)
    {
        arr[i] = input;
        size++;
    }
    return size;
}

void Reverse_array(double * arr, int n)
{
    using namespace std;
    double temp = 0;
    for (size_t start = 1 , end = n - 2 ; start < end ; start++, end--)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }
}

void Show_array(const double * arr, int n)
{
    using namespace std;
    cout << "The numbers of array are:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}