// Create by fuchun on 2025-03-16
#include <iostream>
using namespace std;

struct Student
{
    char first_name[20];
    char last_name[20];
    int age;
    char grade;
};

int main()
{
    Student student;
    cout << "Enter your first name: ";
    cin.getline(student.first_name, 20);
    cout << "Enter your last name: ";
    cin.getline(student.last_name, 20);
    cout << "What letter grade do you deserve? ";
    cin >> student.grade;
    cout << "Enter your age: ";
    cin >> student.age;

    cout << "Name: " << student.last_name << ", " << student.first_name << endl;
    cout << "Age: " << student.age << endl;
    cout << "Grade: " << char(student.grade + 1) << endl;

    return 0;
}