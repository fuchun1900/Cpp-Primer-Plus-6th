#include <iostream>
#ifndef COMPLEX_H_
#define COMPLEX_H_
class Complex
{
private:
    double real;   // real part
    double imag;   // imaginary part
public:
    Complex();                     // default constructor
    Complex(double r, double i = 0.0); // constructor with real and imaginary parts
    ~Complex();                    // destructor
    Complex operator+(const Complex & c) const; // addition operator
    Complex operator-(const Complex & c) const; // subtraction operator
    Complex operator*(const Complex & c) const; // multiplication operator
    Complex operator*(double) const; // multiplication by a scalar
    Complex operator~() const;// conjugate operator 
    
    friend Complex operator*(double d, const Complex & c) // multiplication by a scalar
    {
        return c * d; // use the member function for multiplication
    }
    friend  std::ostream & operator<<(std::ostream & os,const Complex & cp);          // display the complex number
    friend  std::istream & operator>>(std::istream & is, Complex & cp);
};

#endif // COMPLEX_H_