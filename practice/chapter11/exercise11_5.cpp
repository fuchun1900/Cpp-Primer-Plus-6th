#include "stones.h"
using std::cout;

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs) 
{
    stone = int (lbs) / Lbs_per_stn;    // integer division
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds =  stn * Lbs_per_stn +lbs;
}

Stonewt::Stonewt()          // default constructor, wt = 0
{
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()         // destructor
{
}

std::ostream & operator<<(std::ostream & os, const Stonewt & st)
{
   switch (st.mode)
   {
       case Stonewt::STONES:
           os << st.stone << " stone, " << st.pds_left << " pounds\n";
           break;
       case Stonewt::POUNDS_INT:
           os << int(st.pounds + 0.5) << " pounds\n";
           break;
       case Stonewt::POUNDS_FLT:
           os << st.pounds << " pounds\n";
           break;
       default:
           os << "Invalid mode\n";
   }
    return os;
}

Stonewt Stonewt::operator+(Stonewt & st)
{
Stonewt result;
result.pounds = this->pounds + st.pounds;
result.stone = int(result.pounds) / Lbs_per_stn;
result.pds_left = int(result.pounds) % Lbs_per_stn + result.pounds - int(result.pounds);

return result;
}

Stonewt Stonewt::operator-(Stonewt & st)
{
Stonewt diff;
diff.pounds = st.pounds > pounds ? st.pounds - pounds : pounds - st.pounds;
diff.stone = int(diff.pounds) / Lbs_per_stn;
diff.pds_left = int(diff.pounds) % Lbs_per_stn + (diff.pounds - int(diff.pounds));

return diff;
}

Stonewt Stonewt::operator*(double n)
{
    Stonewt mulit(pounds * n);
    
    return mulit;
}

Stonewt operator*(double n, const Stonewt & st)
{
    Stonewt mulit(st.pounds * n);
    
    return mulit;
}
/**
int main()
{
    cout << "Please enter the mode you want: \n";
    cout << "0: STONES, 1: POUNDS_INT, 2: POUNDS_FLT, q:quit\n";
    char ch;
    Stonewt incognito;
    while (std::cin >> ch && ch != 'q')
    {
        while (std::cin.get() != '\n') // discard any extra characters in the input buffer
            continue; // continue to the next iteration
        switch (ch)
        {
            case '0':
                incognito.set_mode(Stonewt::STONES);
                cout << "You have set the mode to STONES.\n";
                cout << "Enter the weight in stones and pounds (e.g., 5 10 for 5 stone 10 pounds): ";
                int stone; double pounds;
                while (!(std::cin >> stone >> pounds))
                {
                    std::cin.clear(); // clear the error flag
                    while (std::cin.get() != '\n') // discard invalid input
                        continue; // continue to the next iteration
                     // discard invalid input
                    cout << "Invalid input. Please enter two numbers (stone and pounds): ";
                }
                incognito = Stonewt(stone, pounds); // create a Stonewt object with the input
                cout << "You have set the weight to " << incognito << "\n";
                break;
            case '1':
                incognito.set_mode(Stonewt::POUNDS_INT);
                cout << "You have set the mode to POUNDS_INT.\n";
                cout << "Enter the weight in pounds (integer): ";
                int pounds_int;
                while (!(std::cin >> pounds_int))
                {
                    std::cin.clear(); // clear the error flag
                    while (std::cin.get() != '\n') // discard invalid input
                        continue; // continue to the next iteration
                    cout << "Invalid input. Please enter an integer for pounds: ";
                }
                incognito = Stonewt(pounds_int); // create a Stonewt object with the input
                cout << "You have set the weight to " << incognito << "\n";
                break;
            case '2':
                incognito.set_mode(Stonewt::POUNDS_FLT);
                cout << "You have set the mode to POUNDS_FLT.\n";
                cout << "Enter the weight in pounds (float): ";
                double pounds_float;
                while (!(std::cin >> pounds_float))
                {
                    std::cin.clear(); // clear the error flag
                    while (std::cin.get() != '\n') // discard invalid input
                        continue; // continue to the next iteration
                    cout << "Invalid input. Please enter a float for pounds: ";
                }
                incognito = Stonewt(pounds_float); // create a Stonewt object with the input
                cout << "You have set the weight to " << incognito << "\n";
                break;
            case 'q':
            case 'Q':
                cout << "Exiting the program.\n";
                return 0; // exit the loop and program
            default:
                cout << "Invalid mode. Please try again.\n";
                continue;
        }
        cout << "Please enter the mode you want: \n";
        cout << "0: STONES, 1: POUNDS_INT, 2: POUNDS_FLT, q:quit\n";
    }
    
    Stonewt wolfe(285.7);    // same as Stonewt wolfe = 285.7;
    Stonewt taft(21, 8);
    

    cout << "The celebrity weighed ";
    cout << incognito; // uses overloaded operator<<
    cout << "The detective weighed ";
    cout << wolfe; // uses overloaded operator<<
    cout << "The President weighed ";
    cout << taft; // uses overloaded operator<<
    cout << "taft + incognito = " << (taft + incognito); // uses overloaded operator+
    cout << "wlofe - incognito = " << (wolfe - incognito); // uses overloaded operator-
    cout << "wlofe * 2 = " << (wolfe * 2); // uses overloaded operator*
    cout << "incognito * 2 = " << (2 * incognito); // uses overloaded operator*

    // std::cin.get();
    return 0;
}
*/