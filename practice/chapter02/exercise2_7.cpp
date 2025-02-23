// Create by fuchun on 2025-02-23

#include <iostream>
using namespace std;
void covertToMinutes(int hours, int minutes) {
    cout << "Time: " << hours << ":" << minutes << endl;

    return;
}

int main() {
    cout << "Enter the number of hours : " << endl;
    int hours;
    cin >> hours;
    cout << "Enter the number of minutes : " << endl;
    int minutes;
    cin >> minutes;

    covertToMinutes(hours, minutes);

    
    return 0;
}