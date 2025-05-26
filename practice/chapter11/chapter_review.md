# 1. Stonewt Stonewt::operator *(double2){
    return Stonewt(pounds * multi)
}

# 2. 友元在不是成员函数，不能用成员运算符掉用。在访问对象的成员时需要加上成员运算符

# 3. 使用类对象的程序可以直接访问调用对象的公共数据接口。无法访问私有数据接口。使用友元函数可以访问公共和私有的数据接口，所有不是必须要友元函数才能访问对象成员

# 4. Stonewt operator * (Stonewt &st , double n) {
    return Stonewt(st.stone * n * st.Lbs_per_stn)
}

# 5, 重载运算符不必都是成员函数，至少一个操作数是用户定义的类型。重载的运算符不能违法愿运算符的语法规则。 不错创建新运算符
s
# operator double{
    (retrun mag)}   