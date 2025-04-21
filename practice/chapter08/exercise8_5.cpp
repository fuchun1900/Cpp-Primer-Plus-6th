//
// Created by fuchun on 4/21/25.
//
#include <iostream>

template <typename T> T max5(T arr[]);
const int len = 5;

int main()
{
   ;
    int arr1[len] = {1, 2, 3, 4, 5};
    double arr2[len] = {1.1, 7.2, 3.3, 4.4, 5.5};
    char arr3[len] = {'a', 'g', 'c', 'd', 'e'};

    std::cout << "Max of arr1: " << max5(arr1) << std::endl;
    std::cout << "Max of arr2: " << max5(arr2) << std::endl;
    std::cout << "Max of arr3: " << max5(arr3) << std::endl;

    return 0;
}

template <typename T> T max5(T arr[])
{
    T max = arr[0];
    for (size_t i = 1; i < len; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
