//
// Created by fuchun on 4/21/25.
//

#include <iostream>
using namespace std;
#include <cstring>

struct stringy
{
    char * str;
    int ct;
};

void set(stringy & s, char * str);
void show(const char * str ,int times = 1);
void show(const stringy & s, int times = 1);

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");

    return 0;
}

void set(stringy & s, char * str)
{
    s.ct = strlen(str);
    s.str = new char[s.ct + 1];
    strcpy(s.str, str);
}
void show(const char * str, int times)
{
     while (times-- > 0)
        cout << str << endl;
}
void show(const stringy & s, int times)
{
    while (times-- > 0)
        cout << s.str << endl;
}