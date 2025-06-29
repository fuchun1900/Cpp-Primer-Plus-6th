//base class
#ifndef CLASSIC_H_
#define CLASSIC_H_

#include <iostream>
class Cd
{
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;

public:
    Cd(const char * s1 = "none", const char * s2 = "none",
       int n = 0, double x = 0.0);
    Cd(const Cd & d);
    virtual ~Cd() {}
    virtual void Report() const;
    Cd & operator=(const Cd & d);
    //friend std::ostream & operator<<(std::ostream & os, const Cd & d);
};


class Classic : public Cd
{
private:
    char works[50];
public:
    Classic(const char * s1 = "none", const char * s2 = "none",
            const char * s3 = "none", int n = 0, double x = 0.0);
    Classic(const Cd & d, const char * s3);
    Classic(const Classic & c);
    virtual ~Classic() {}
    virtual void Report() const;
    Classic & operator=(const Classic & c);
    //friend std::ostream & operator<<(std::ostream & os, const Classic & c);
};

#endif