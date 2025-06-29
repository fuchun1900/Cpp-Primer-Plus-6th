using namespace std;
#include "classic2.h"
#include "cstring"

// Classic methods
Cd:: Cd(const char * s1,const char * s2, int n, double x)
{
    performers = new char[strlen(s1) + 1];
    label = new char[strlen(s2) + 1];
    if (performers == nullptr || label == nullptr)
    {
        cerr << "Memory allocation failed.\n";
        exit(EXIT_FAILURE);
    }
    strcpy(performers,s1);
    strcpy(label,s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd& d)
{
    performers = new char[strlen(d.performers) + 1];
    label = new char[strlen(d.label) + 1];
    if (performers == nullptr || label == nullptr)
    {
        cerr << "Memory allocation failed.\n";
        exit(EXIT_FAILURE);
    }
    // Copy the contents of the source object
    strcpy(performers, d.performers);
    strcpy(label,d.label);
    selections = d.selections;
    playtime = d.playtime;
}

void Cd::Report() const
{
    cout << performers << ':' << label << ':' << selections << ':' << playtime << endl;
}

Cd & Cd:: operator=(const Cd & d)
{
    if (this == &d)
        return *this;
    // Free existing memory
    delete[] performers;
    delete[] label;
    performers = new char[strlen(d.performers) + 1];
    label = new char[strlen(d.label) + 1];
    if (performers == nullptr || label == nullptr)
    {
        cerr << "Memory allocation failed.\n";
        exit(EXIT_FAILURE);
    }
    // Copy the contents of the source object
    strcpy(performers, d.performers);
    strcpy(label,d.label);
    selections = d.selections;
    playtime = d.playtime;

    return *this;
}

Classic :: Classic(const char * s1, const char * s2, const char * s3, int n, double x)
:Cd(s1, s2, n, x)
{
    works = new char[strlen(s3) + 1];
    if (works == nullptr)
    {
        cerr << "Memory allocation failed.\n";
        exit(EXIT_FAILURE);
    }
    strcpy(works, s3);
}

Classic::Classic(const Cd & d, const char * s3)
: Cd(d)
{
    works = new char[strlen(s3) + 1];
    if (works == nullptr)
    {
        cerr << "Memory allocation failed.\n";
        exit(EXIT_FAILURE);
    }
    strcpy(works, s3);
}
Classic::Classic(const Classic & c)
: Cd(c)
{   
    works = new char[strlen(c.works) + 1];
    if (works == nullptr)
    {
        cerr << "Memory allocation failed.\n";
        exit(EXIT_FAILURE);
    }
    // Copy the contents of the source object  
    strcpy(works, c.works);
}
Classic & Classic::operator=(const Classic & c)
{
    if (this == &c)
        return *this;
    Cd::operator=(c);
    // Free existing memory
    delete[] works;
    works = new char[strlen(c.works) + 1];
    strcpy(works, c.works);
    return *this;
}
void Classic::Report() const
{
    Cd::Report();
    cout << "Classic: " << works << endl;
}

Cd::~Cd()
{
    delete[] performers;
    delete[] label;
}
Classic::~Classic()
{
    delete[] works;
}

void Bravo(const Cd & d)
{
    d.Report();
    cout << endl;
}
int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2("Piano Sonata No in B flat", "Chopin", "Philps", 3, 12.5);
    Cd *pcd = &c1;
    Classic *pcc = &c2;

    cout << "Using object directly:\n";
    c1.Report();
    cout << endl;
    c2.Report();
    cout << endl;

    cout << "Using type cd pointer to objects:\n";
    pcd->Report();
    cout << endl;
    pcc->Report();
    cout << endl;

    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);

    cout << "Testing assignment:\n";
    Cd copy;
    copy = c2;  // use assignment operator
    cout << "Using object copy:\n";
    copy.Report();

    return 0;
}