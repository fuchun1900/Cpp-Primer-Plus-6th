#include "complex.h"

Complex::Complex() : real(0.0), imag(0.0) {}
Complex::Complex(double r, double i) : real(r), imag(i) {}
Complex::~Complex() {}
Complex Complex::operator+(const Complex & c) const {
    return Complex(real + c.real, imag + c.imag);
}  
Complex Complex::operator-(const Complex & c) const {
    return Complex(real - c.real, imag - c.imag);
}
Complex Complex::operator*(const Complex & c) const {
    return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}
Complex Complex::operator*(double d) const{
    return Complex(real * d, imag * d);
}    
Complex Complex::operator~() const {
    return Complex(real, -imag);
}

std::ostream & operator<<(std::ostream & os,const Complex & cp) {
    os << "(" << cp.real << ", " << cp.imag << "i)";
    return os;
}

std::istream & operator>>(std::istream & is,Complex & cp) {
    std::cout << "real: ";
    if (!(is >> cp.real)) {
        std::cerr << "Invalid input for real part. Please enter a number.\n";

        return is; // return the stream in a failed state
    }
    std::cout << "imaginary: ";
    if (!(is >> cp.imag)) {
        std::cerr << "Invalid input for real part. Please enter a number.\n";

        return is; // return the stream in a failed state
    }
    return is; // return the stream in a good state
}

int main() {
    Complex a(3.0, 4.0);
    Complex c;
    std::cout << "Enter a complex number (real and imaginary parts,q to quit):\n ";
    while (std::cin >> c) {
        std::cout << "c is  " << c << "\n";
        std::cout << "complex conjugate is " << ~c << "\n";
        std::cout << "a + c = " << (a + c) << "\n";
        std::cout << "a - c = " << (a - c) << "\n";
        std::cout << "a * c = " << (a * c) << "\n";
        std::cout << "a * 2.0 = " << (2 * c) << "\n";

        std::cout << "Enter another complex number (real and imaginary parts,q to quit): ";
    }
    std::cout << "Exiting the program.\n";
    

    return 0;
}