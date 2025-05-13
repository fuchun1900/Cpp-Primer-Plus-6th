#ifndef PERSON_H_
#define PERSON_H_
#include <iostream>
#include <string>
#include <cstring>

class Person
{
private:
    static const int LIMIT = 25;
    std::string lname;
    char fname[LIMIT];
public:
    Person()
    {
        lname = "";
        fname[0] = '\0';
    }
    Person(const std::string &ln, const char *fn = "Heyyou");
    void Show() const;
    void FormalShow() const;
};

Person::Person(const std::string &ln, const char *fn)
{
    lname = ln;
    std::strncpy(fname, fn, LIMIT - 1);
    fname[LIMIT - 1] = '\0';
}


void Person::Show() const
{
    std::cout << "Name: " << fname << " " << lname << "\n";
}

void Person::FormalShow() const
{
    std::cout << "Name: " << lname << ", " << fname << "\n";
}

#endif