#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string line;
    ifstream fin1("file1.txt",ios_base::in);
    ifstream fin2("file2.txt",ios_base::in);
    ofstream fout("merged.txt",ios_base::out);
    if(!fin1.is_open() || !fin2.is_open() || !fout.is_open())
    {
        cerr << "Could not open files.\n";
        exit(EXIT_FAILURE);
    }
    while(!fin1.eof() || !fin2.eof())
    {
        if(getline(fin1,line)&&!line.empty())
            fout << line ;
        if(getline(fin2,line)&&!line.empty())
            fout << line;  
        fout << endl;
    }

    fin1.close();
    fin2.close();
    fout.close();       

    return 0;

}