// Create by fuchun on 2025-03-05
#include <iostream>

const int trans_factor = 60;

int main()
{
    using namespace std;
    float degrees, minutes, seconds;
    cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
    cout << "First, enter the degrees: ";
    cin >> degrees;
    cout << "Next, enter the minutes of arc: ";
    cin >> minutes;
    cout << "Finally, enter the seconds of arc: ";
    cin >> seconds;

    double latitude = degrees + minutes / trans_factor + seconds / (trans_factor * trans_factor);
    cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = " << latitude << " degrees" << endl;
    
    return 0;
}