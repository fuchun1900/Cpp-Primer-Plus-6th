#ifndef GOLF_H_
#define GOLF_H_
#include <iostream>

class golf
{
private:
    static const int LEN = 40;
    char fullname[LEN];
    int handicap;
    /* data */
public:
    golf();
    golf(const char * name , int hc);
    void showgolf()const;
    void set(int hc);
};

#endif