#ifndef EMP_H_
#define EMP_H_
#include <iostream>
#include <string>

class abstr_emp {
private:
    std::string fname;
    std::string lname;
    std::string job;
public:
    abstr_emp() : fname("no first name"), lname("no last name"), job("no job") {}
    abstr_emp(const std::string & fn, const std::string & ln, const std::string & j)
        : fname(fn), lname(ln), job(j) {}
    virtual ~abstr_emp() = 0; // pure virtual function
    virtual void ShowAll() const = 0;
    virtual void SetAll() = 0;
    friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);
};
class employee : public abstr_emp {
    public:
        employee() : abstr_emp() {}
        employee(const std::string & fn, const std::string & ln, const std::string & j)
            : abstr_emp(fn, ln, j) {}
        virtual ~employee() {}
        virtual void ShowAll() const override;
        virtual void SetAll() override;
};
class manager : virtual public abstr_emp {
private:
    int inchargeof; // number of employees managed
protected:
    int InChargeOf() const { return inchargeof; }
    int & InChargeOf() { return inchargeof; }
public:
    manager() : abstr_emp(), inchargeof(0) {}
    manager(const std::string & fn, const std::string & ln, const std::string & j, int ico = 0)
        : abstr_emp(fn, ln, j), inchargeof(ico) {}
    manager(const abstr_emp & e, int ico = 0)
        : abstr_emp(e), inchargeof(ico) {}
    manager(const manager & m)
        : abstr_emp(m), inchargeof(m.inchargeof) {}
    virtual ~manager() {}
    virtual void ShowAll() const override;
    virtual void SetAll() override;
};
class fink : virtual public abstr_emp {
private:
    std::string reportsto; // name of person to report to
protected:
    const std::string & ReportsTo() const { return reportsto; }
    std::string & ReportsTo() { return reportsto; }
public:
    fink() : abstr_emp(), reportsto("no one") {}
    fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rto = "no one")
        : abstr_emp(fn, ln, j), reportsto(rto) {}
    fink(const abstr_emp & e, const std::string & rto = "no one")
        : abstr_emp(e), reportsto(rto) {}
    fink(const fink & e)
        : abstr_emp(e), reportsto(e.reportsto) {}
    virtual ~fink() {}
    virtual void ShowAll() const override;
    virtual void SetAll() override;
};
class highfink : public manager, public fink {
public:
    highfink() : abstr_emp(), manager(), fink() {}
    highfink(const std::string & fn, const std::string & ln, const std::string & j, int ico = 0, const std::string & rto = "no one")
        : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rto) {}
    highfink(const abstr_emp & e, int ico = 0, const std::string & rto = "no one")
        : abstr_emp(e), manager(e, ico), fink(e, rto) {}
    highfink(const manager & m, const fink & f)
        : abstr_emp(m), manager(m), fink(f) {}
    virtual ~highfink() {}
    virtual void ShowAll() const override;
    virtual void SetAll() override;
};


#endif // EMP_H_