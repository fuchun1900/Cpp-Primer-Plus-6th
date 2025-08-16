// sales.cpp -- Sales implementation
#include "/home/DEV/C++_Project/Cpp-Primer-Plus-6th/bookcodes/chapter15/sales.h"
#include <iostream>
using std::string;


Sales::bad_index::bad_index(int ix, const string & s )
    : std::logic_error(s), bi(ix)
{
}

Sales::Sales(int yy)
{
    year = yy;
    for (int i = 0; i < MONTHS; ++i)
        gross[i] = 0;
}

Sales::Sales(int yy, const double * gr, int n)
{
    year = yy;
    int lim = (n < MONTHS)? n : MONTHS;
    int i;
    for (i = 0; i < lim; ++i)
        gross[i] = gr[i];
    // for i > n and i < MONTHS
    for ( ; i < MONTHS; ++i)
        gross[i] = 0;
}

double Sales::operator[](int i) const
{
    if(i < 0 || i >= MONTHS)
        throw bad_index(i);
    return gross[i];
}

double & Sales::operator[](int i)
{
    if(i < 0 || i >= MONTHS)
        throw bad_index(i);
    return gross[i];
}

LabeledSales::nbad_index::nbad_index(const string & lb, int ix,
           const string & s ) : Sales::bad_index(ix, s)
{
    lbl = lb;
}

LabeledSales::LabeledSales(const string & lb, int yy)
         : Sales(yy)
{
    label = lb;
}

LabeledSales::LabeledSales(const string & lb, int yy, const double * gr, int n)
        : Sales(yy, gr, n)
{
    label = lb;
}

double LabeledSales::operator[](int i) const
{    if(i < 0 || i >= MONTHS)
        throw nbad_index(Label(), i);
    return Sales::operator[](i);
}

double & LabeledSales::operator[](int i)
{
    if(i < 0 || i >= MONTHS)
        throw nbad_index(Label(), i);
    return Sales::operator[](i);
}

int main() {
    // Example usage of Sales and LabeledSales
    double salesData1[12] = {1000, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200};
    double salesData2[12] = {1100, 1150, 1200, 1250, 1300, 1350, 1400, 1450, 1500, 1550, 1600, 1650};
    Sales sales1(2024, salesData1, 12);
    LabeledSales labeledSales("2023 Sales", 2023, salesData2, 12);

    try {
        for (int i = 0; i < Sales::MONTHS; ++i) {
            std::cout << "Month " << i + 1 << ": " << labeledSales[i] << std::endl;
        }
        std::cout << "Label: " << labeledSales.Label() << std::endl;
        sales1[13] = 2500; // This will throw an exception
    } catch (const Sales::bad_index & e) {
         if(typeid(e) == typeid(LabeledSales::nbad_index)) {
            const LabeledSales::nbad_index & nbi = dynamic_cast<const LabeledSales::nbad_index &>(e);
            std::cerr << nbi.what()<< "LabeledSales bad index: " << nbi.label_val() << " at index " << nbi.bi_val() << std::endl;
        }else {
            std::cerr << e.what() << "Sales bad index: " << e.bi_val() << std::endl;
        }
    }

    try {
        labeledSales[13] = 2600; // This will also throw an exception
    } catch (const Sales::bad_index & e) {
        if(typeid(e) == typeid(LabeledSales::nbad_index)) {
            const LabeledSales::nbad_index & nbi = dynamic_cast<const LabeledSales::nbad_index &>(e);
            std::cerr << nbi.what()<< "LabeledSales bad index: " << nbi.label_val() << " at index " << nbi.bi_val() << std::endl;
        }else {
            std::cerr << "Sales bad index: " << e.bi_val() << std::endl;
        }
    }

    return 0;
}