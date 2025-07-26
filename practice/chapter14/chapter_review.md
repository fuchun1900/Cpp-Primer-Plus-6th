# 1. public private public private private  
# 2. Gloam::Gloam(int g, const char *s ): fb(s) { glip = g}
# Gloam::Gloam(int g, const Frabjous & f): fb(f) { glip = g}
# void Glam::tell() {fb.tell(); cout << glip << endl}
# 3. Gloam::Gloam(int g , const char * s):Frabjous(s){glip = g}
# Gloam::Gloam(int g, const Frabjous & f): Frabjous(f){glip = g}
# void Gloam::tell(){Frabjous::tell(); cout glip << endl}
# 4. Stack<Worker *>
{
    private:
        enum {MAX = 10};
        Worker * items[MAX];
        int top;
    public:
        Stack();
        bool isempty();
        boll isfull();
        bool push(const Worker *& item);
        bool pop(Worker *& item);
};
# 5. tempalte <class T , int n > class ArraryTP; tempalte <class Type> class Stack;
# ArraryTP<string, 100> sa;
# Stack<ArraryTP<double , 100>> Stack_Arr;
# ArraryTP<Stack < Work *>,100> arr_stk_wpr
# 6. 一个派生类的有多个基类，如果多个基类没有继承关系，那么这个派生类将继承所有基类的成员和成员函数。如果基类存在相同的祖先，那么就会重复继承相同的成员，采用虚基类，那么派生类只会继承祖先的成员的同一个副本。同时不采用虚基类继承，那么在不使用类名限定情况下，同名数据成员会产生二义性。采用虚基类那么派生类的同名成员优先于直接或间接祖先的相同名称，即使不使用限定符也不会有二义性。