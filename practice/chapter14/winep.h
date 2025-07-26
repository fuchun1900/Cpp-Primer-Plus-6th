# ifndef _WINEP_H_
# define _WINEP_H_

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
    Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) {}
    Pair() {}
};

class wine: private PairArray, private std::string
{
    private:
        int years;
    public:
        wine(const char* l, int y, const int yr[], const int bot[]);
        wine(const char * l, int y);
        void GetBottles();
        const std::string& GetLabel() const;
        int sum() const;
        void Show();
        ~wine();
        // Additional methods can be added here if needed
};
# endif