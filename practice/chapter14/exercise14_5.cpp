#include "emp.h"

abstr_emp::~abstr_emp() {}

void abstr_emp::ShowAll() const {
    std::cout << "Employee: " << *this;
}
void abstr_emp::SetAll() {
    std::cout << "Enter employee's first name: ";
    std::getline(std::cin, fname);
    std::cout << "Enter employee's last name: ";
    std::getline(std::cin, lname);
    std::cout << "Enter employee's job: ";
    std::getline(std::cin, job);
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e) {
    os << "First Name: " << e.fname << "\n"
       << "Last Name: " << e.lname << "\n"
       << "Job: " << e.job << "\n";
    return os;
}

void employee::ShowAll() const {
    abstr_emp::ShowAll();
}
void employee::SetAll() {
    abstr_emp::SetAll();
}

void manager::ShowAll() const {
    abstr_emp::ShowAll();
    std::cout << "In charge of " << inchargeof << " employees.\n";
}
void manager::SetAll() {
    abstr_emp::SetAll();
    std::cout << "Enter number of employees managed: ";
    std::cin >> inchargeof;
    while (std::cin.get() != '\n') // clear the input buffer
        continue;
}

void fink::ShowAll() const {
    abstr_emp::ShowAll();
    std::cout << "Reports to: " << reportsto << "\n";
}
void fink::SetAll() {
    abstr_emp::SetAll();
    std::cout << "Enter name of person to report to: ";
    std::getline(std::cin, reportsto);
}

void highfink::ShowAll() const {
    fink::ShowAll();
    std::cout << "In charge of " << InChargeOf() << " employees.\n";
}
void highfink::SetAll() {
    fink::SetAll();
    std::cout << "Enter number of employees managed: ";
    std::cin >> InChargeOf();
    while (std::cin.get() != '\n') // clear the input buffer
        continue;
}

int main()
{
    employee emp("John", "Doe", "Developer");
    emp.ShowAll();
    emp.SetAll();
    emp.ShowAll();

    manager mgr("Jane", "Smith", "Manager", 5);
    mgr.ShowAll();
    mgr.SetAll();
    mgr.ShowAll();

    fink fin("Alice", "Johnson", "Fink", "Bob");
    fin.ShowAll();
    fin.SetAll();
    fin.ShowAll();

    highfink hf("Charlie", "Brown", "Highfink", 10, "Dave");
    hf.ShowAll();
    hf.SetAll();
    hf.ShowAll();
    
    abstr_emp *emps[4] = { &emp, &mgr, &fin, &hf };
    for (size_t i = 0; i < 4; i++)
        emps[i]->ShowAll();
    

    return 0;
}