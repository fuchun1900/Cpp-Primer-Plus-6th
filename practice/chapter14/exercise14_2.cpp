#include "winep.h"

template <class T1, class T2> T1& Pair<T1,T2>::first()
{
    return a;
}

template <class T1, class T2> T2& Pair<T1,T2>::second()
{
    return b;
}

wine::wine(const char* l, int y, const int yr[], const int bot[])
    : std::string(l), years(y), PairArray(ArrayInt(yr, y), ArrayInt(bot, y))
{
}
wine::wine(const char * l, int y)
    : std::string(l), years(y), PairArray(ArrayInt(0,0), ArrayInt(0,0))
{
}
void wine ::GetBottles()
{
    std::cout << "Enter " <<(*this) <<" data for " <<
    years << " year(s) and bottle(s):\n";
    for (int i = 0; i < years; ++i)
    {
        std::cout << "Year: ";
        std::cin >> (*this).first()[i];
        std::cout << "Bottles: ";
        std::cin >> this->second()[i]; //私有继承在类成员内部时可以隐式向上转换
    }
}

const std::string& wine::GetLabel() const
{
    return (const std::string&)*this; //私有继承在类成员内部时可以隐式向上转换
}
int wine::sum() const
{
    return this->second().sum();
}
void wine::Show()
{
    std::cout << "Wine: " << *this << "\n";
    std::cout << "Years: " << years << "\n";
    for (int i = 0; i < years; ++i)
    {
        std::cout << first()[i] << ": " << PairArray::second()[i] << " bottles\n";
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