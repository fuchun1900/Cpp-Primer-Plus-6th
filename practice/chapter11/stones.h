#ifndef STONES_H_
#define STONES_H_
#include <iostream>
class Stonewt
{
public:
    enum MODE{STONES, POUNDS_INT,POUNDS_FLT}; // enum for weight types
private:
    enum {Lbs_per_stn = 14};      // pounds per stone
    int stone;                    // whole stones
    double pds_left;              // fractional pounds
    double pounds;                // entire weight in pounds
    MODE mode = POUNDS_FLT;                // current mode for output
public:
    Stonewt(double lbs);          // constructor for double pounds
    Stonewt(int stn, double lbs); // constructor for stone, lbs
    void set_mode(MODE m) { mode = m; } // set the mode
    Stonewt();                    // default constructor
    ~Stonewt();
    Stonewt operator+(Stonewt & st); // add Stonewt object
    Stonewt operator-(Stonewt & st); // subtract Stonewt object
    Stonewt operator*(double n);     // multiply Stonewt object by n
    bool operator<=(const Stonewt & st) const // less than or equal to
    {
        return pounds <= st.pounds;
    }
    bool operator>=(const Stonewt & st) const // greater than or equal to
    {
        return pounds >= st.pounds;
    }
    bool operator<(const Stonewt & st) const // less than
    {
        return pounds < st.pounds;
    }
    bool operator>(const Stonewt & st) const // greater than
    {
        return pounds > st.pounds;
    }
    bool operator==(const Stonewt & st) const // equal to
    {
        return pounds == st.pounds;
    }
    bool operator!=(const Stonewt & st) const // not equal to
    {
        return pounds != st.pounds;
    }
    friend std::ostream & operator<<(std::ostream & os, const Stonewt & st); // output Stonewt object
    friend Stonewt operator*(double n, const Stonewt & st); // multiply n by Stonewt object
};
#endif