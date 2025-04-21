//
// Created by fuchun on 4/21/25.
//
#include <iostream>
#include <cstring>

template <typename T> T maxn(T arr[],int len);
template <>const char * maxn< const char *>(const char * arr[],int len);


int main()
{
    int arr1[6] = {1, 3, 6, 5, 2, 5};
    double arr2[4] = {1.1, 7.2, 3.3, 4.4};
    const char * arr3[3] = {"english" , "chinese", "japanese"};

    std::cout << "Max of arr1: " << maxn(arr1,6) << std::endl;
    std::cout << "Max of arr2: " << maxn(arr2,4) << std::endl;
    std::cout << "Max of arr3: " << maxn(arr3,3) << std::endl;
    return 0;
}

template <typename T> T maxn(T arr[],int len)
{
    T max = arr[0];
    for (size_t i = 1; i < len; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

template <> const char * maxn<const char *>(const char * arr[],int len)
{
    const char * temp = arr[0];
    int max = strlen(arr[0]);
    for (size_t i = 1; i < len; i++)
    {
        if (strlen(arr[i])> max)
        {
            max = strlen(arr[i]);
            temp = arr[i];
        }
    }
    return temp;
}