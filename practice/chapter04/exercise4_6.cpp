// Create by Shujia Huang on 2021-07-25
#include <iostream>
#include <string>
using namespace std;

struct CandyBar
{
    string brand;
    double weight;
    int calories;
};

int main()
{
    CandyBar shops[3] ={
    {"Mocha Munch", 2.3, 350},
    {"Big Rabbit", 5, 300},
    {"Joy Boy", 4.1, 430}
    };

    for (int i = 0; i < 3; i++)
    {
        cout << "Brand: " << shops[i].brand << endl;
        cout << "Weight: " << shops[i].weight << endl;
        cout << "Calories: " << shops[i].calories << endl;
    }

    return 0;
}

