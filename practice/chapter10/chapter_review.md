# 1. 类是用户定义的包含数据成员和对数据的操作的集合
# 2. 类通过访问控制来实现对数据的封装、从类外部无法访问类的基本数据，只能通过类对象实体和类的公有成员进行访问
# 3. 类是对象的模版，对象是类的实体
# 4. 类的数据成员描述类的基本数据构成，函数成员是对类的操作功能的定义。类的数据成员由每一个对象独享，而类的所有对象恭喜同一组函数
# 5. class BankAccount{
private:
    string fullname;
    string bankid;
    double balance;

public:
    BankAcount();
    BankAcount(const string &name ,const string &id , double bal);
    ~BankAcount();
    void show() const;
    void save(double cash);
    void take(double cash);
}
# 6. 类的构造函数在创建对象时使用，类的析构函数在对象生命周期完成调用
# 7. BankAcçount::BankAcçount(const string name, const bankid ,double bal){
    fullname = name;
    bankid = id;
    blance = bal;
}
  BankAcçount::BankAcçount(){
    fullname = "";
    bankid = "";
    blance = 0;
}
# 8. 默认构造函数是没有参数的构造函数，如果在定义类时没有定义构造函数，那么编译器会自动创建一个默认构造函数。如果显式指定义自定义构造函数，则必须手动定义默认构造函数。
# 9. 
#include <string>

class Stock
{
private:
    std::string company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    Stock();        // default constructor
    Stock(const std::string & co, long n = 0, double pr = 0.0);
    ~Stock();       // do-nothing destructor
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show()const;
    const Stock & topval(const Stock & s) const;
    double shareval() cosnt {
        return share_val;
    }
    double total_val() const{
        return totla_val;
    }
    const std::string & showCompany(){
        return company;
    }
};

#endif
# 10. this 是指向调用函数的类生成对象的指针，*this是对象本身