#include <iostream>
int main()
{
    char input;
    int count = 0;
    std::cout << "Enter a phase: ";
    while(std::cin.peek()!= '$')
    {
        std::cin.get(input);
        count++;
    }
    std::cout << "You entered " << count << " characters.\n";
    return 0;
}