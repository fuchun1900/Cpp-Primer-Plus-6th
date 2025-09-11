#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

vector<int> Lotto(int dot, int sdot);



int main()
{
    vector<int> winner;
    winner = Lotto(51, 6);
    cout << "The winning numbers are: ";
    for (auto num : winner)
        cout << num << " ";
    cout << endl;
    return 0;
}

vector<int> Lotto(int dot, int sdot)
{
    srand((unsigned int)time(0));
    vector<int> lottery,temp;
    for (int i = 1; i <= dot; i++)
        temp.push_back(rand()%dot);
    random_shuffle(temp.begin(), temp.end());
    for (int i = 0; i < sdot; i++)
        lottery.push_back(temp[i]);

    return lottery;
}