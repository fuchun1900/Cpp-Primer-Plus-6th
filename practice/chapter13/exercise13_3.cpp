# include "dma.h"
#include <cstring>

// Abstract Base Class
AcctABC::AcctABC(const char * l, int r)
{
    label = new char[strlen(l) + 1];
    if (label == nullptr)
    {
        std::cerr << "Memory allocation failed.\n";
        exit(EXIT_FAILURE);
    }
    strcpy(label, l);
    rating = r;
}
AcctABC::AcctABC(const AcctABC & rs)
{
    label = new char[strlen(rs.label) + 1];
    if (label == nullptr)
    {
        std::cerr << "Memory allocation failed.\n";
        exit(EXIT_FAILURE);
    }
    strcpy(label, rs.label);
    rating = rs.rating;
}
void AcctABC::view()
{
    std::cout << "Label: " << label << std::endl;
    std::cout << "Rating: " << rating << std::endl;
}
AcctABC::~AcctABC()
{
    delete[] label;
}

// baseDMA methods
baseDMA::baseDMA(const char * l, int r) : AcctABC(l, r) {}
baseDMA::baseDMA(const baseDMA & rs) : AcctABC(rs){}
void baseDMA::view()
{
    AcctABC::view();
}
baseDMA::~baseDMA() {}


//  lacksDMA methods
lacksDMA::lacksDMA(const char * c, const char * l, int r)
    : AcctABC(l, r)
{
    strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}
lacksDMA::lacksDMA(const char * c, const baseDMA & rs)
    : AcctABC(rs)
{
    strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}
void lacksDMA::view()
{
    AcctABC::view();
    std::cout << "Color: " << color << std::endl;
}

// derived class with DMA
hasDMA::hasDMA(const char * s, const char * l, int r)
    : AcctABC(l, r)
{
    style = new char[strlen(s) + 1];
    if (style == nullptr)
    {
        std::cerr << "Memory allocation failed.\n";
        exit(EXIT_FAILURE);
    }
    strcpy(style, s);
}
hasDMA::hasDMA(const char * s, const baseDMA & rs)
    : AcctABC(rs)
{
    style = new char[strlen(s) + 1];
    if (style == nullptr)
    {
        std::cerr << "Memory allocation failed.\n";
        exit(EXIT_FAILURE);
    }
    strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA & hs)
    : AcctABC(hs)
{
    style = new char[strlen(hs.style) + 1];
    if (style == nullptr)
    {
        std::cerr << "Memory allocation failed.\n";
        exit(EXIT_FAILURE);
    }
    strcpy(style, hs.style);
}
hasDMA::~hasDMA()
{
    delete[] style;
}
hasDMA & hasDMA::operator=(const hasDMA & rs)
{
    if (this == &rs)
        return *this;
    AcctABC::operator=(rs);
    delete[] style;
    style = new char[strlen(rs.style) + 1];
    if (style == nullptr)
    {
        std::cerr << "Memory allocation failed.\n";
        exit(EXIT_FAILURE);
    }
    strcpy(style, rs.style);
    return *this;
}

void hasDMA::view()
{
    AcctABC::view();
    std::cout << "Style: " << style << std::endl;
}
std::ostream & operator<<(std::ostream & os, const AcctABC & rs)
{
    os << "Label: " << rs.label << std::endl;
    os << "Rating: " << rs.rating << std::endl;

    return os;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
   os << (const AcctABC &) rs; // Cast to base class
    return os;
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & rs)
{
    os << (const AcctABC &) rs; // Cast to base class
    os << "Color: " << rs.color << std::endl;
    return os;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & rs)
{
    os << (const AcctABC &) rs; // Cast to base class
    os << "Style: " << rs.style << std::endl;
    return os;
}

int main()
{
    AcctABC * arr[3]; // Array of pointers to AcctABC
    // Example usage
    arr[0] = new baseDMA("Base Account", 5);
    arr[1] = new lacksDMA("Red", "Lacks Account", 3);
    arr[2] = new hasDMA("Modern", "Has Account", 4);
    for (int i = 0; i < 3; ++i)
    {
        arr[i]->view(); // Polymorphic call
        std::cout << std::endl;
    }

    return 0;
}