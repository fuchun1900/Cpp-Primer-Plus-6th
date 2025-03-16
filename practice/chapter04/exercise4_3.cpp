// Create by fuchun on 2025-03-16
#include <iostream>
#include <cstring>

int main(void)
{
    using namespace std;
    char fist_name[20];
    char last_name[20];
    char full_name[40];

    cout << "Enter your first name: ";
    cin.getline(fist_name, 20);
    cout << "Enter your last name: ";
    cin.getline(last_name, 20);

    strcpy(full_name, last_name);
    strcat(full_name, ", ");
    strcat(full_name, fist_name);

    cout << "Here's the information in a single string: " << full_name << endl;
}


