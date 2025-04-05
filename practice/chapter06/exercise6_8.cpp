// Create by fuchun on 2025-04-05
#include <iostream>
#include <fstream>
#include <string>
using  namespace std;
int main()
{
    ifstream inFile;
    char filename[100];
    cout << "Enter the file name: ";
    cin.getline(filename, 100);
    inFile.open(filename);
    if (!inFile)
    {
        cout << "Could not open the file " << filename << endl;
        exit(EXIT_FAILURE);
    }
    char readfile;
    int count = 0;
    while (inFile >> readfile)
    {
        if (isblank(readfile))
            continue;
        count++;
    }
    cout << "The number of characters in the file is: " << count << endl;
    inFile.close();
    return 0;

}


