// Create by fuchun on 2025-03-16
#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string first_name;
    string last_name;
    string full_name;

    cout << "Enter your first name: ";
    getline(cin, first_name);
    cout << "Enter your last name: ";
    getline(cin, last_name);
    
    full_name = last_name + ", " + first_name;
    
    cout << "Here's the information in a single string: " << full_name << endl;

    return 0;
}