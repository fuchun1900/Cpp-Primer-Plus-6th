#ifndef PORT_H_
#define PORT_H_
#include <iostream>
#include <cstring>

class Port
{
private:
    char * brand;  // pointer to brand name
    int bottles;   // number of bottles
    char style[20]; // style of port, e.g., tawny, ruby, vintage
public:
    Port(const char * br = "none", int b = 0, const char * st = "none");
    Port(const Port & p); // copy constructor
    virtual ~Port(){delete[] brand;} // destructor;
    Port & operator=(const Port & p); // assignment operator
    Port & operator+=(int b); // add bottles
    Port & operator-=(int b); // remove bottles
    int BottleCount() const { return bottles; }
    virtual void Show() const;
    friend std::ostream & operator<<(std::ostream & os, const Port & p);
};

class VintagePort : public Port
{
private:
    char * nickname; // nickname for vintage port
    int year; // year of vintage
public:
    VintagePort(const char * br = "none", int b = 0, const char * st = "none",
                const char * nn = "none", int y = 0);
    VintagePort(const Port & vp, const char * nn = "none", int y = 0); // constructor by Port object
    VintagePort(const VintagePort & vp); // copy constructor
    ~VintagePort() { delete[] nickname; } // destructor
    VintagePort & operator=(const VintagePort & vp); // assignment operator
    void Show() const override; // override Show method
    friend std::ostream & operator<<(std::ostream & os, const VintagePort & vp);
};

#endif // PORT_H_