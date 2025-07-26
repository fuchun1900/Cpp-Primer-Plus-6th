# ifndef _WINEC_H_
# define _WINEC_H_

#include <iostream>
#include <string>
#include <valarray>

template <class T1, class T2> class Pair;
typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt,ArrayInt> PairArray;

template <class T1, class T2> class Pair
{ 
private:
    T1 a;
    T2 b;

    public:
    T1 & first();
    T2 & second();
    T1 first() const { return a; }
    T2 second() const { return b; }
    Pair(const T1 & a, const T2 & b) : a(a), b(b) {}
    Pair() {}
};

class wine
{
private:
    std::string label;
    PairArray info;
    int years;
public:
    wine(const char* l, int y, const int yr[], const int bot[]);
    wine(const char * l, int y);
    void GetBottles();
    const std::string& GetLabel() const;
    int sum() const;
    void Show();
    ~wine();
};

# endif