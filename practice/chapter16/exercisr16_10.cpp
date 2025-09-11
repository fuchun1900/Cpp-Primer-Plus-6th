// vect3.cpp -- using STL functions
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

struct Review {
    std::string title;
    int rating;
    double price;
};

bool operator<(const std::shared_ptr<Review> & p1, const std::shared_ptr<Review> & p2);
bool worseThan(const std::shared_ptr<Review> & p1, const std::shared_ptr<Review> & p2);
bool expensiveThan(const std::shared_ptr<Review> & p1, const std::shared_ptr<Review> & p2);
bool FillReview(Review & rr);
void ShowReview(const std::shared_ptr<Review> & ptr);
int main()
{
    using namespace std;

    vector<std::shared_ptr<Review>>books;
    Review temp;
    while (FillReview(temp)){
        std::shared_ptr<Review> ptr = std::make_shared<Review>(temp);
        books.push_back(ptr);
    }
    cout <<"Choose your choice to sort the book list:\n"
         <<"a. alphabetically\n"
         <<"b. Sorted by rate in ascending order \n"
         <<"c. Sorted by rate in descending order\n"
         <<"d. Sorted by price in ascending order\n"
         <<"e. Sort by price in descending order\n"
         <<"f. default order\n "
         <<"q. quit\n";
    char choice;
    while (cin >> choice && choice != 'q')
    {
        switch (choice)
        {
          case 'a': 
            sort(books.begin(), books.end());
            break;
          case 'b':
            sort(books.begin(), books.end(), worseThan);
            break;
          case 'c':
            sort(books.rbegin(), books.rend(), worseThan);
            break;
          case 'd':
            sort(books.begin(), books.end(), expensiveThan);
            break;
          case 'e':
            sort(books.rbegin(), books.rend(), expensiveThan);
            break;
          case 'f':
            std::random_shuffle(books.begin(), books.end());
            break;
          default:
            cout << "Invalid choice\n";
            continue;
        }
        cout << "Rating\tBook\t\t\tPrice\n";
        for_each(books.begin(), books.end(), ShowReview);
        cout << "Choose your choice to sort the book list:\n"
         <<"a. alphabetically\n"
         <<"b. Sorted by rate in ascending order \n"
         <<"c. Sorted by rate in descending order\n"
         <<"d. Sorted by price in ascending order\n"
         <<"e. Sort by price in descending order\n"
         <<"f. default order\n"
         <<"q. quit\n";
    }
    cout << "Bye.\n";
    // cin.get();
    return 0;
}

bool operator<(const std::shared_ptr<Review> & p1, const std::shared_ptr<Review> & p2)
{
    if (p1->title < p2->title)
        return true;
    else if (p1->title == p2->title && p1->rating < p2->rating)
        return true;
    else
        return false;
}   

bool worseThan(const std::shared_ptr<Review> & p1, const std::shared_ptr<Review> & p2)
{
    if (p1->rating < p2->rating)
        return true;
    else
        return false;
}

bool expensiveThan(const std::shared_ptr<Review> & p1, const std::shared_ptr<Review> & p2)
{
    if (p1->price < p2->price)
        return true;
    else
        return false;
}

bool FillReview(Review & rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin,rr.title);
    if (rr.title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    std::cout << "Enter book price: ";
    std::cin >> rr.price;
    if (!std::cin)
        return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const std::shared_ptr<Review> & ptr)
{
    std::cout << ptr->rating << "\t" << ptr->title <<"\t" << ptr->price << std::endl;
}
