#include <iostream>
using namespace std;
const int SLEN = 30;
struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};
int getifo(student pa[], int n);
void display1(student st);
void display2(const student * ps); 
void display3(const student pa[], int n);

int main()
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        continue;

    student * ptr_stu = new student[class_size];
    int entered = getifo(ptr_stu, class_size);
    for (int i = 0; i < entered; i++)
    {
        cout << "Student #" << (i + 1) << ":\n";
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    cout << "Done.\n";

    return 0;
}

int getifo(student pa[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << "Enter name: ";
        cin.getline(pa[i].fullname, SLEN);
        if (pa[i].fullname[0] == '\0')
        {
            cout << "No name entered; input process terminated.\n";
            return i;
        }
            
        cout << "Enter hobby: ";
        cin.getline(pa[i].hobby, SLEN);
        cout << "Enter ooplevel: ";
        cin >> pa[i].ooplevel;
        if (!cin.good())
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; input process terminated.\n";
            (i == 0)? i:i--;
            continue;
        }
        while (cin.get() != '\n')
            continue;
    }
    return i;
}

void display1(student st)
{
    cout << "Name: " << st.fullname << endl;
    cout << "Hobby: " << st.hobby << endl;
    cout << "Ooplevel: " << st.ooplevel << endl;
}

void display2(const student * ps)
{
    cout << "Name: " << ps->fullname << endl;
    cout << "Hobby: " << ps->hobby << endl;
    cout << "Ooplevel: " << ps->ooplevel << endl;
}

void display3(const student pa[], int n)
{
    cout << "Name\tHobby\tOoplevel\n";
    for (int i = 0; i < n; i++)
    {
        cout << pa[i].fullname << "\t" << pa[i].hobby << "\t" << pa[i].ooplevel << endl;
    }
}