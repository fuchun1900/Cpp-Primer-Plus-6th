#include "port.h"

Port::Port(const char * br, int b, const char * st)
{
    brand = new char[strlen(br) + 1];
    if (brand == nullptr)
    {
        std::cerr << "Memory allocation failed.\n";
        exit(EXIT_FAILURE);
    }
    strcpy(brand, br);
    bottles = b;
    strncpy(style, st, sizeof(style) - 1);
    style[sizeof(style) - 1] = '\0'; // Ensure null termination
}
Port::Port(const Port & p)
{
    brand = new char[strlen(p.brand) + 1];
    if (brand == nullptr)
    {
        std::cerr << "Memory allocation failed.\n";
        exit(EXIT_FAILURE);
    }
    strcpy(brand, p.brand);
    bottles = p.bottles;
    strncpy(style, p.style, sizeof(style) - 1);
    style[sizeof(style) - 1] = '\0'; // Ensure null termination
}
Port & Port::operator=(const Port & p)
{
    if (this == &p)
        return *this;
    delete[] brand; // Free existing memory
    brand = new char[strlen(p.brand) + 1];
    if (brand == nullptr)
    {
        std::cerr << "Memory allocation failed.\n";
        exit(EXIT_FAILURE);
    }
    strcpy(brand, p.brand);
    bottles = p.bottles;
    strncpy(style, p.style, sizeof(style) - 1);
    style[sizeof(style) - 1] = '\0'; // Ensure null termination
    return *this;
}
Port & Port::operator+=(int b)
{
    if (b < 0)
    {
        std::cerr << "Cannot add negative bottles.\n";
        return *this;
    }
    bottles += b;
    return *this;
}
Port & Port::operator-=(int b)
{
    if (b < 0)
    {
        std::cerr << "Cannot remove negative bottles.\n";
        return *this;
    }
    if (b > bottles)
    {
        std::cerr << "Not enough bottles to remove.\n";
        return *this;
    }
    bottles -= b;
    return *this;
}
void Port::Show() const
{
    std::cout << "Brand: " << brand << "\n"
              << "Bottles: " << bottles << "\n"
              << "Style: " << style << std::endl;
}
std::ostream & operator<<(std::ostream & os, const Port & p)
{
    os << "Brand: " << p.brand << ", Bottles: " << p.bottles
       << ", Style: " << p.style;
    return os;
}
VintagePort::VintagePort(const char * br, int b, const char * st,
                         const char * nn, int y)
    : Port(br, b, st)
{
    nickname = new char[strlen(nn) + 1];
    if (nickname == nullptr)
    {
        std::cerr << "Memory allocation failed.\n";
        exit(EXIT_FAILURE);
    }
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const Port & vp, const char * nn , int y)
    : Port(vp) // Call base class constructor
{
    nickname = new char[20]; // Default nickname
    if (nickname == nullptr)
    {
        std::cerr << "Memory allocation failed.\n";
        exit(EXIT_FAILURE);
    }
    strcpy(nickname, nn);
    year = y; // Default year
}
VintagePort::VintagePort(const VintagePort & vp)
    : Port(vp)
{
    nickname = new char[strlen(vp.nickname) + 1];
    if (nickname == nullptr)
    {
        std::cerr << "Memory allocation failed.\n";
        exit(EXIT_FAILURE);
    }
    strcpy(nickname, vp.nickname);
    year = vp.year;
}
VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if (this == &vp)
        return *this;
    Port::operator=(vp); // Call base class assignment operator
    delete[] nickname; // Free existing memory
    nickname = new char[strlen(vp.nickname) + 1];
    if (nickname == nullptr)
    {
        std::cerr << "Memory allocation failed.\n";
        exit(EXIT_FAILURE);
    }
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}
void VintagePort::Show() const
{
    Port::Show(); // Call base class Show method
    std::cout << "Nickname: " << nickname << "\n"
              << "Year: " << year << std::endl;
}
std::ostream & operator<<(std::ostream & os, const VintagePort & vp)
{
    os << static_cast<const Port &>(vp) // Cast to base class
       << ", Nickname: " << vp.nickname
       << ", Year: " << vp.year;
    return os;
}
// Example usage
int main()
{
    Port p1("Porto", 10, "Ruby");
    VintagePort vp1("Vintage Porto", 5, "Tawny", "Old Vintage", 1980);

    std::cout << "Port Details:\n";
    p1.Show();
    std::cout << p1 << std::endl;

    std::cout << "\nVintage Port Details:\n";
    vp1.Show();
    std::cout << vp1 << std::endl;
    std::cout << "\nUsing constructor by Port object:\n";
    VintagePort vp2(p1 ,"Janes", 1977); // Test constructor with Port object
    vp2.Show();
    std::cout << vp2 << std::endl;
    std::cout << "\nUsing assignment operator:\n";
    VintagePort vp3;
    vp3 = vp1; // Test assignment operator
    vp3.Show();
    std::cout << vp3 << std::endl;
    p1 = vp3; // Test assignment with base class
    std::cout << "\nAfter assignment with base class:\n";
    p1.Show();
    std::cout << p1 << std::endl;

    std::cout << "\nUsing += and -= operators:\n";
    p1 += 5; // Add bottles
    std::cout << "After adding 5 bottles:\n";
    p1.Show();
    std::cout << p1 << std::endl;
    p1 -= 3; // Remove bottles
    std::cout << "\nAfter removing 3 bottles:\n";
    p1.Show();
    std::cout << p1 << std::endl;

    return 0;
}