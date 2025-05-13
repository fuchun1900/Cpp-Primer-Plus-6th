# include <iostream>
# include <cstring>
# include "golf.h"

int main()
{
    golf ann("Ann Bird free" ,24);
    golf andy;

    ann.showgolf();
    ann.set(20);
    ann.showgolf();
    andy.showgolf();

}

golf::golf(const char * name, int hc)
{
    std::strncpy(fullname, name, LEN - 1);
    fullname[LEN - 1] = '\0';
    handicap = hc;
}

golf::golf()
{
    fullname[LEN] = '\0';
    handicap = 0;
    std::cout << " Please enter your name: ";
    std::cin.getline(fullname, LEN);
    std::cout << " Please enter your handicap: ";
    while (!(std::cin >> handicap) || handicap < 0)
    {
        std::cin.clear();
        while (std::cin.get() != '\n')
            continue;
        std::cout << " Please enter a valid handicap: ";
    }
    std::cout << fullname << " : " << handicap << std::endl;
}

void golf::showgolf() const
{
    std::cout << "Name: " << fullname << "\n";
    std::cout << "Handicap: " << handicap << "\n";
}

void golf::set(int hc)
{
    handicap = hc;
}
