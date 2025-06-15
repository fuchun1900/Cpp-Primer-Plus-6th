// stock20.cpp -- augmented version
#include <iostream>
#include "stock.h"
using namespace std;
// constructors
Stock::Stock()        // default constructor
{
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
    company = new char[1]();
}

Stock::Stock(const std::string & co, long n, double pr)
{
    company = new char[co.length() + 1];
    std::strcpy(company, co.c_str());
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
                   << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

// class destructor
Stock::~Stock()        // quiet class destructor
{
    delete [] company;
}

// other methods
void Stock::buy(long num, double price)
{
     if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

std::ostream & operator<<(std::ostream & os, const Stock & s)
{
    using std::ios_base;
    // set format to #.###
    ios_base::fmtflags orig = 
        os.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = os.precision(3);

    os << "Company: " << s.company
       << "  Shares: " << s.shares << '\n';
    os << "  Share Price: $" << s.share_val;
    // set format to #.##
    os.precision(2);
    os << "  Total Worth: $" << s.total_val << '\n';

    // restore original format
    os.setf(orig, ios_base::floatfield);
    os.precision(prec);
    return os;
}

const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this; 
}

Stock::Stock(const Stock & s)
{
    company - new char[strlen(s.company) + 1];
    strcpy(company, s.company);
    shares = s.shares;
    share_val = s.share_val;
    total_val = s.total_val; 
}

Stock & Stock::operator=(const Stock & s)
{
    if (this == &s)
        return *this;
    delete [] company;
    company = new char[strlen(s.company) + 1];
    strcpy(company, s.company);
    shares = s.shares;
    share_val = s.share_val;
    total_val = s.total_val; 

    return *this;   
}


const int STKS = 4;
int main()
{
    {
// create an array of initialized objects
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
        };

    std::cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < STKS; st++)
        std::cout << stocks[st];
// set pointer to first element
    const Stock * top = &stocks[0];
    for (st = 1; st < STKS; st++)
        top = &top->topval(stocks[st]);
// now top points to the most valuable holding
    std::cout << "\nMost valuable holding:\n";
	std::cout << *top;
    }
    // std::cin.get();
    return 0; 
}

