# 1. class RQ1{
    private:
        string st;
    public:
        RQ1():st(" "){}
        RQ1(const char * s):st(s){}
        ~RQ1(){};
};

# 2. 自动管理内存，有多种api可以使用，可以重载加法运算符实现拼接。

# 3. void ToUpper(stiring &s){
    for(int i = 0; i < s.size(); i++)
        s[i] = toupper(s[i]);
};

# 4. auto_ptr<int> pia(new int(20)). auto_ptr<string> ps (new string). 智能指针只能用于new生成的堆内存。所有不能用在已有变量内存。

# 5.栈只能实现先进先出，导致第一个放进袋子的被反复存取，如果想提取第一个放进袋子的，需要提取之前所有的高尔夫球套，所以并不效率

# 6. set会导致合并重复数据。

# 7. 因为指针适应容器内部复杂的数据类型和数据组织形式，比如链表和数值之间使用指针的方法不同

# 8. 

# 9. 可以创建多种数据类型的统一化容器，并具公用接口维和和管理，可以自动调整长度不用担心数组越界

# 10. random_shuffle()函数要求使用随机访问迭代器。list对象只有双向迭代器。

# 11.  先初始化函数类 toobig的成员cutoff为10，并传入参数15。返回的是true

