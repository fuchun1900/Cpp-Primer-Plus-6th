#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;
const int LIMIT = 50;

void ShowStr(const string & str);
void GetStrs(ifstream & fin, vector<string> & str_vec);

class Store
{
    private:
        string str;
        ofstream * fout;
    public:
        Store(ofstream &out):fout(&out)  { }
        bool operator()(const string & s);
        ~Store() {}
};

void ShowStr(const string & str)
{
    cout << str << endl;
}

void GetStrs(ifstream & fin, vector<string> & v)
{
    unsigned int len;
    char * p;
    while (fin.read((char *)&len, sizeof len))
    {
        p = new char[len];
        fin.read((char *)p, len);
        v.push_back(string (p,len));
        delete [] p;
    }
}

bool Store::operator()(const string & s)
{
    unsigned int len = s.length();
    fout->write((char *)&len, sizeof len);
    fout->write(s.data(), len);
    return true;
}

int main()
{
    using namespace std;
    vector<string> str_vec;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if(!fin.is_open())
    {
        cerr << "Could not open strings.dat for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, str_vec);
    fin.close();

    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    if(!fout.is_open())
    {
        cerr << "Could not open strings.dat for output.\n";
        exit(EXIT_FAILURE);
    }
    Store store(fout);
    for_each(str_vec.begin(), str_vec.end(), store);
    fout.close();

    return 0;
}