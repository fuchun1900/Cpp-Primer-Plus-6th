#include <iostream>
#include "mytime.h"

int main()
{
    using std::cout;
    using std::endl;
    Time aida(3, 35);
    Time tosca(4, 48);
    Time temp;

    cout << "Aida and Tosca:\n";
    cout << aida<<"; " << tosca << endl;
    temp = aida + tosca;     // operator+()
    cout << "Aida + Tosca: " << temp << endl;
    cout << "Tosca - Aida: " << tosca - aida << endl; // operator-()
    temp = aida* 1.17;  // member operator*()
    cout << "Aida * 1.17: " << temp << endl;
    cout << "10.0 * aida: " << 10.0 * aida << endl;
	// std::cin.get();
    return 0; 
}
