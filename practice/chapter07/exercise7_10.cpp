#include <iostream>

double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double div(double a, double b);
double calculate(double a, double b, double (*pf)(double, double));

int main()
{
    double (*pf[4])(double, double) = {add, sub, mul, div};

    double a, b;
    std::cout << "Please enter two numbers:  \n";
    std::cout << "Press Q to quit.\n";  
    while (std::cin >> a >> b)
    {
        std::cout << "Please enter the operation you want to do:\n";
        std::cout << "1: add\n2: sub\n3: mul\n4: div\n";
        int op;
        std::cin >> op;
        switch (op)
        {
        case 1:
            std::cout << "The result is: " << calculate(a, b, pf[0]) << '\n';
            break;
        case 2:
            std::cout << "The result is: " << calculate(a, b, pf[1]) << '\n';
            break;
        case 3:
            std::cout << "The result is: " << calculate(a, b, pf[2]) << '\n';
            break;
        case 4:
            std::cout << "The result is: " << calculate(a, b, pf[3]) << '\n';
            break;
        
        default:
            std::cout << "Invalid operation.\n";
            std::cout << "Please enter again.\n";
            break;
        }
        std::cout << "Please enter the operation you want to do:\n";
    }
    std::cout << "Bye.\n";

    return 0;
}

double add(double a, double b)
{
    return a + b;
}
double sub(double a, double b)
{
    return a - b;
}
double mul(double a, double b)
{
    return a * b;
}
double div(double a, double b)
{
    if (b == 0)
    {
        std::cout << "Error: division by zero.\n";
        return 0;
    }
    return a / b;
}
double calculate(double a, double b, double (*pf)(double, double))
{
    return pf(a, b);
}