# include <iostream>
# include <cstring>
# include "golf.h"

int main()
{
    using std::cout;
    using std::endl;
    using std::cin;

    const int MEMBER = 3;
    golf g[MEMBER];
    for (size_t i = 0; i < MEMBER; i++)
    {
        cout << "Enter the name of the golfer #" << i + 1 << ": ";
        if (setgolf(g[i]) == 0)
            break;
    }
    cout << "The golfers are:\n";
    for (const golf &golf : g)
    {
        if (golf.fullname[0] == '\0')
            break;
        showgolf(golf);
    }
    return 0;
}