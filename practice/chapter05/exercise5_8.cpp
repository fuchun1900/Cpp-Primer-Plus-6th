// Create by fuchun on 2025-03-26
#include <cstring>
#include <iostream>

int main()
{
    using namespace std;
    int counts = 0;
    char words[100];
    cout << "Enter words (to stop,type the word done):" << endl;

    do
    {
        cin >> words;
        counts++;
        cin.get();
    } while (strcmp(words, "done") != 0);
    
    cout << "You entered a total of " << counts - 1  << " words." << endl;

    
    return 0;
}
