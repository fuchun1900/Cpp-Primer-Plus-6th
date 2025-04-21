# 1.The function is short and simple
# 2. void song(const char * name, int times = 1)
     if the argument for times is omit , the default argument for time is 1.
     void song(int times = 1 ,const char * name = "O, MYy Papa")
# 3. void iquote(int) , void iquote(double) , void iquote(char *)
# 4. void display(box& b){
    cout << b.maker << endl;
    cout << b.heigut << endl;
    cout << b.width << endl;
    cout << b.length << endl;
    cout << b.volume << endl;

    void set_volume(box& b){
        b.volume = b.height * b.width * b.length;
    }
}
# 5. void fill(std::arrary<double,Season>& pa){
    using namespace std;
    for(int i = 0; i < Season; i++){
        cout << "Enter" << Sname[i] << "expenses:";
        cin >> pa[i];
    }
}
   void show(std::array<double,Season>& pa){
    using namespace std;
    double total = 0;
    cout << "\nExpenses\n";

    for(int i = 0; i < Season; i++){
        cout << Sname[i] << ":$ " << da[i] << endl;
        total += da[i];
    }
    cout <<"Total Expenses : $ " << total << endl;
}
# 6.  a .double mass(double density , double volume)  double mass(double desity , double volume = 1.0)
#     b. void repeat(int n ,const char * str)  void repeat(const char * str)
#     c. int average(int a, int b)  double average(double a, double b)
#     They have same function signature so that cant't be overloding.

# 7. templat<Typename T> T function(const T& a ,const T& b){
    return (a > b)? a : b; 
}

# 8. template<> box& bigger<box>(box& a, box& b){
    retrurn (a.volume > b.volume)? a : b;
}

# 9. v1 float  v2 float&  v3 float&  v4 int  v5 double