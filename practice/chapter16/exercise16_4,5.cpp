#include <iostream>
#include <list>
#include <string>


template <typename T>std::list<T> reduce(T * arr, int n);

int main()
{
    using std::cout;
    using std::endl;
    int arr1[6] = {1, 2, 3, 4, 5, 6};
    double arr2[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::string arr3[5] = {"hello", "world", "this", "is","hello"};
    auto lst1 = reduce(arr1, sizeof(arr1)/sizeof(int));
    auto lst2 = reduce(arr2, sizeof(arr2)/sizeof(double));
    auto lst3 = reduce(arr3, sizeof(arr3)/sizeof(std::string));

    for (auto it = lst3.begin(); it != lst3.end(); it++)
    {
        cout << *it << " ";
    }
    
    return 0;
}

template <typename T>std::list<T> reduce(T * arr, int n)
{
    std::list<T> lst(arr, arr + n);
    lst.sort();
    lst.unique();

    return lst;
}

