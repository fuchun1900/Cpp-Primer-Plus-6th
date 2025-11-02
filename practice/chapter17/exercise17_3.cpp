#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
    if (argc < 3)
    {
        cout << "Useage: " << argv[0] << "srcfile desfile" << endl;
        exit(EXIT_FAILURE);
    }
    char ch;
    ifstream fin(argv[1],ios_base::in);
    ofstream fout(argv[2],ios_base::out);
    if(!fin.is_open() || !fout.is_open())
    {
        cerr << "Could not open files.\n";
        exit(EXIT_FAILURE);
    }
    while(fin.read((char *)&ch,sizeof ch))
    {
        fout.write((char *)&ch,sizeof ch); 
    }
    fin.close();
    fout.close();
    return 0;

}
    