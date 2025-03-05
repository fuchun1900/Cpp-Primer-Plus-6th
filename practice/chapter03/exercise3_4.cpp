// Create by fuchun on 2025-03-05
#include <iostream>

const int hour_of_day = 24;
const int minute_of_hour = 60;
const int second_of_minute = 60;

int main ()
{
    using namespace std;
    long long seconds;
    cout << "Enter the number of seconds: ";
    cin >> seconds;

    int minutes = seconds / second_of_minute;
    int hours = minutes / minute_of_hour;
    int days = hours / hour_of_day;

    cout << seconds << " seconds = " << days << " days, " << hours % hour_of_day << " hours, " << minutes % minute_of_hour << " minutes, " << seconds % second_of_minute << " seconds" << endl;
}