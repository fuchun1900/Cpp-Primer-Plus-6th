#include <iostream>
#include <fstream>

int main(int argc, char * argv[])
{
    if(argc == 1)
    {
        std::cerr << "Usage: " << argv[0] << " filename[s]\n";
        exit(EXIT_FAILURE);
    }
    char ch;
    std::ofstream fout(argv[1],std::ios_base::out);
    if(fout.is_open())
    {
        std::cout << "Input the data:\n";
        while (std::cin.get(ch) && ch != EOF)
        {
            fout << ch;
        }
    }

    else
    {
        std::cerr << "Could not open " << argv[1] << " for output.\n";
        exit(EXIT_FAILURE);
    }
    fout.close();   

    return 0;
}