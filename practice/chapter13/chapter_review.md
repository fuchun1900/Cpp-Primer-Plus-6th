# 1.从基类中继承类数据成员和类成员函数
# 2. 构造函数、析构函数、赋值函数
# 3. 如果返回void则无法用于连续赋值语句中。返回baseDMA则是定义了基类中的赋值函数，可以用于比较其他类型。
# 4. 当派生类构造对象时，先构造基类对象，再构造派生类对象。调用析构函数时先调用派生类析构函数，再调用基类析构函数。（构造派生类对象时在派生类传入基类初始化列表的值来构造基类）
# 5. 需要构造函数
# 6. 如果是派生类对象调用方法则调用派生类的方法
# 7. 如果派生类中类型成员为指针变量，在构造时使用了堆内存，则需要单独为派生类设计一个赋值函数，用于销毁原先指针指向的堆内存，并开辟新的堆内存
# 8. 将基类指针或引用指向派生类对象时，不需要显式类型转换。如果将派生类指针会应用指向基类对象时，需要显式类型转换来调用基类的方法部分。容易产生问题
# 9. 将派生类对象赋值给基类对象时，会将派生类的基类数据部分赋值给基类对象。如果将基类对象赋值给派生类，则只对派生类的基类部分对应的基类成员进行复制
# 10. 因为基类的指针或引用可以指向派生类，因为派生类包含了基类的所有部分，所有使用基类指针来调用方法不会产生任何问题。
# 11. 如果函数中的参数类型为基类，那么将派生类参数传入函数时会调用基类的复制构造函数，这个构造函数的参数是基类的引用类型，可以引用派生类，所有复制构造函数会用派生类对象来初始化相对应的基类数据部分。
# 12. 用引用不会调用复制构造函数，所有更有效率
# 13. 如果是普通函数那么调用的是基类的函数，如果是虚拟函数那么调用派生类的函数
# 14. 派生类需要使用基类的公开函数来访问基类的私有数据成员。