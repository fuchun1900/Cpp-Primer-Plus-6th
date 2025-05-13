#include <iostream>
#include <cstring>

class plorg
{
private:
    char plorgname[20];
    int cl;
public:
    plorg(const char * name = "Plorga", int c = 50);
    void setcl(int c);
    void show() const;
};

plorg::plorg(const char * name, int c)
{
    std::strncpy(plorgname, name, 20);
    plorgname[19] = '\0';
    cl = c;
}

void plorg::setcl(int c)
{
    cl = c;
}
void plorg::show() const
{
    std::cout << "Name: " << plorgname << "\n";
    std::cout << "Cl: " << cl << "\n";
}

int main()
{
    plorg p1;
    p1.show();
    p1.setcl(100);
    p1.show();

    plorg p2("Lady", 75);
    p2.show();

    return 0;
}
