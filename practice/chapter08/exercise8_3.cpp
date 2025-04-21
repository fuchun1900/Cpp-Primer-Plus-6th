//
// Created by fuchun on 4/21/25.
//
#include <iostream>
#include <string>
#include <cstring>

std::string transfer(const std::string & str);
int main()
{
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);
    while (str.size() != 1 || str[0] != 'q')
    {
        std::cout << "The string is: " << str << std::endl;
        std::cout << "The transfered string is: " << transfer(str) << std::endl;
        std::cout << "Enter a string: ";
        std::getline(std::cin, str);
    }

    std::cout << "Bye!" << std::endl;

    return 0;
}

std::string transfer(const std::string & str)
{
    std::string result;
    for (size_t i = 0; i < str.size(); i++)
        result.push_back(toupper(str[i]));
    
     
    return result;
}