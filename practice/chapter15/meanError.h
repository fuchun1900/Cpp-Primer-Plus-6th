#ifndef __MEANERROR_H__
#define __MEANERROR_H__
#include<iostream>

class meanError : public std::logic_error
{
private:
    double v1;
    double v2;
public:
    meanError(double a = 0.0, double b = 0.0 , std::string msg = "mean error")
    : v1(a), v2(b), logic_error{msg} {}
    ~meanError(){};
    virtual void mseg() const noexcept; // Pure virtual function for error message
};

class bad_hmean : public meanError
{
public:
    bad_hmean(double a = 0.0, double b = 0.0, std::string msg = "Hmean : Invalid argument")
    : meanError(a, b, msg) {}
    void mseg() const noexcept override {
        std::cout << "Harmonic mean error: " << what() << "\n";
    }
};

class bad_gmean : public meanError
{
public:
    bad_gmean(double a = 0.0, double b = 0.0, std::string msg = "Gmean : Invalid argument")
    : meanError(a, b, msg) {}
    void mseg() const noexcept override {
        std::cout << "Geometric mean error: " << what() << "\n";
        std::cout << "Values used: " ;
        meanError::mseg();
    }
};
#endif

inline void meanError::mseg() const noexcept {
    std::cout << v1 << ", " << v2 << "\n";
}