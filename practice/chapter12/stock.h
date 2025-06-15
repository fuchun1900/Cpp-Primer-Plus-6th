//modified by: fuchun
#ifndef STOCK_H_
#define STOCK_H_
#include <string>
#include <cstring>
class Stock
{
private:
    char * company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    Stock();        // default constructor
    Stock(const std::string & co, long n = 0, double pr = 0.0);
    Stock(const Stock & s); // copy constructor
    ~Stock();       // do-nothing destructor
    Stock & operator=(const Stock & s); // assignment operator
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    //void show()const;
    const Stock & topval(const Stock & s) const;
    friend std::ostream & operator<<(std::ostream & os, const Stock & s);
};

#endif
