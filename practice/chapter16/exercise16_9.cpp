#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

const int LENTH = 10000000;

int main()
{
    std::vector<int> vi0;
    srand((unsigned int)time(0));
    for (int i = 0; i < LENTH; i++)
        vi0.push_back(rand() % 10000);
    std::list<int> si0(vi0.begin(), vi0.end());
    std::vector<int> vi1(vi0);

    clock_t start, end;
    start = clock();
    std::sort(vi0.begin(), vi0.end());
    end = clock();
    std::cout << "vector sort time: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    start = clock();
    si0.sort();
    end = clock();
    std::cout << "list sort time: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl; 

    si0.assign(vi0.begin(), vi0.end());
    start = clock();
    std::copy(si0.begin(), si0.end(), vi1.begin());
    std::sort(vi1.begin(), vi1.end());
    si0.assign(vi1.begin(), vi1.end());

    end = clock();
    std::cout << "list copy to vector, sort and copy back time: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;


    return 0;

}