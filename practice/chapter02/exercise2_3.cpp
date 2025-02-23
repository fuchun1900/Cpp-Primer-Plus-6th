// Create by Shujia Huang on 2021-07-19
#include <iostream>

using namespace std;
void blind_mice(int);
void how_they_run();

void blind_mice(int n) {
    if (n > 0)
    {
        cout << "Three blind mice." << endl;
        blind_mice(n - 1);
    }
    else if (n == 0)
    {
        return;
    }
    
    how_they_run();
    
    return;
}

void how_they_run() {
    cout << "See how they run" << endl;
    return;
}

int main() {

    blind_mice(2);

    return 0;
}