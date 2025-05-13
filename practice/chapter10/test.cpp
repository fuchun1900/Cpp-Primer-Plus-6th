#include <iostream>
#include <string>
#include "Banker.h"

int main()
{
    std::string name;
    std::string id;
    double balance;

    std::cout << " Please enter your name: ";
    std::getline(std::cin, name);
    std::cout << " Please enter your bank ID: ";
    std::getline(std::cin, id);
    std::cout << " Please enter your initial balance: ";
    std::cin >> balance;
    BankAccount account(name, id, balance);
    int choice;
    do
    {
        std::cout << " Please enter the number you want to operate: \n";
        std::cout << " 1. Show your account information \t " << "2. Save money \t " << "3. Take money \t " << "4. Exit \n";

        std::cin >> choice;
        switch (choice)
        {
            case 1:
                account.show();
                break;
            case 2:
                double save_amount;
                std::cout << " Please enter the amount you want to save: ";
                std::cin >> save_amount;
                account.save(save_amount);
                break;
            case 3:
                double take_amount;
                std::cout << " Please enter the amount you want to take: ";
                std::cin >> take_amount;
                account.take(take_amount);
                break;
            case 4:
                std::cout << " Exiting the program. \n";
                break;
            default:
                std::cout << " Invalid choice. Please try again. \n";
        }
    } while (choice != 4);
    return 0;
}