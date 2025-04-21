//
// Created by fuchun on 4/21/25.
//
# include <iostream>
# include <cstring>

struct CandyBar
{
    char brand[40];
    float weight;
    int calories;
};
void insert(CandyBar &cb, const char * brand = "Millennium Munch", float weight = 2.85, int calories = 350)
{
    std::strcpy(cb.brand, brand);
    cb.weight = weight;
    cb.calories = calories;
}
void display(const CandyBar &cb)
{
    std::cout << "Brand: " << cb.brand << std::endl;
    std::cout << "Weight: " << cb.weight << std::endl;
    std::cout << "Calories: " << cb.calories << std::endl;
}

int main()
{
    CandyBar cb1;
    insert(cb1);
    display(cb1);
    std::cout << std::endl;
    CandyBar cb2;
    insert(cb2, "Snickers", 1.5, 250);
    display(cb2);
    std::cout << std::endl;
    CandyBar cb3;
    insert(cb3, "Mars", 2.0);
    display(cb3);
    std::cout << std::endl;

    return 0;
}