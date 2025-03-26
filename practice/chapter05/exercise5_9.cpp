#include <iostream>
#include <string>

int main()
{
    using namespace std;
    int counts = 0;
    string words;
    cout << "Enter words (to stop,type the word done):" << endl;

    do
    {
        cin >> words;
        counts++;
        cin.get();
    } while (words != "done");
    
    cout << "You entered a total of " << counts - 1  << " words." << endl;

    
    return 0;
}