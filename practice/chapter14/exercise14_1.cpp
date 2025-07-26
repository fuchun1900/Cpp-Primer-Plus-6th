#include "winec.h"

template <class T1, class T2> T1& Pair<T1,T2>::first()
{
    return a;
}

template <class T1, class T2> T2& Pair<T1,T2>::second()
{
    return b;
}

wine::wine(const char* l, int y, const int yr[], const int bot[])
    : label(l), years(y), info(ArrayInt(yr, y), ArrayInt(bot, y))
{
}

wine::wine(const char * l, int y)
    : label(l), years(y), info(ArrayInt(y), ArrayInt(y))
{
}
void wine::GetBottles()
{
    std::cout << "Enter " << years << " year(s) and bottle(s):\n";
    for (int i = 0; i < years; ++i)
    {
        std::cout << "Year: ";
        std::cin >> info.first()[i];
        std::cout << "Bottles: ";
        std::cin >> info.second()[i];
    }
}
const std::string& wine::GetLabel() const
{
    return label;
}
int wine::sum() const
{
    return info.second().sum();
}
void wine::Show()
{
    std::cout << "Wine: " << label << "\n";
    std::cout << "Years: " << years << "\n";
    for (int i = 0; i < years; ++i)
    {
        std::cout << info.first()[i] << ": " << info.second()[i] << " bottles\n";
    }
}
wine::~wine()
{   
    // Destructor logic if needed
}

int main()
{
    std::cout << "Enter name of wine: ";
    std::string name;
    std::getline(std::cin, name);
    std::cout << "Enter number of years: ";
    int years;
    std::cin >> years;
    wine holding(name.c_str(), years);
    holding.GetBottles();
    holding.Show();

    const int yr[] = { 1993, 1995, 1998 };
    const int bot[] = { 48, 60, 72 };
    wine more("Gushing Grape Red", 3, yr, bot);
    more.Show();
    std::cout << "Total bottles in " << more.GetLabel() << ": " << more.sum() << "\n";
    std::cout << "Bye!\n";
    return 0;
}