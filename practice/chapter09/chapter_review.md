# 1. a automatic stroage  b. outer static storage  c. inner static storage d. static staorage in block
# 2. using declaration makes a single name avilable , In contrast the using directive makes all the name avilable.
# if you use a using directive to import a name  that is already declared in a function ,the local name will hide the namespace name. If the same name is already declared in a function ,you cant import the same name with using delcaration.
# 3.# include <iostrean>
#     int main(){
      double x;
      std::cout << "Enter value:";
      while(!(std::cin >> x)){
        std::cout << "Bad input. please enter a number:";
        std::cin.clear();
        while(std::cin.get()!='\n')
            continue;
      }
      std::cout << "Value = " << x << std::endl;
      return 0;
}
# 4. #include<iostream>
     int main(){
        using std::cin;
        using std:cout;
        using std::endl
        double x;
        cout << "Enter value:";
        while(!(cin >> x)){
            cout << "Bad input.Please enter an number:";
            cin.clear();
            while(cin.get()!='\n')
                continue;
        }
        cout << "Value=" << x << endl;
     }
# 5. One way is using the namespace ,another way is using the inner static function defination in seprate file confined the function is inner linker function.
# 6. 10 4 0 
#  10 1
#  10 0
# 7. 1 
    4 1 2 
    2 
    2 
    4 1 2 
    2
#