# include <iostream>
# include <fstream>
# include <set>

using namespace std;

int main()
{
    fstream fin_mat("mat.txt",ios_base::in);
    fstream fin_pat("pat.txt",ios_base::in);
    ofstream fout("matpat.txt",ios_base::out);
    string line;
    set<string> mat_set;
    set<string> pat_set;
    set<string> guest_set;

    if(!fin_mat.is_open() || !fin_pat.is_open() || !fout.is_open())
    {
        cerr << "Could not open files.\n";
        exit(EXIT_FAILURE);
    } 

    while (fin_mat >> line)
    {
        mat_set.insert(line);
        guest_set.insert(line);
    }
    while (fin_pat >> line)
    {
        pat_set.insert(line);
        guest_set.insert(line);
    }
    cout << "Matinee guests:\n";
    for(const auto & name : mat_set)
        cout << name << endl;
    cout << "\nPatinee guests:\n";
    for(const auto & name : pat_set)
        cout << name << endl;
    cout << "\nAll guests:\n";
    for(const auto & name : guest_set)
    {
        fout << name << endl;
        cout << name << endl;
    }   
    fin_mat.close();
    fin_pat.close();
    fout.close();

    return 0;
    
    
}