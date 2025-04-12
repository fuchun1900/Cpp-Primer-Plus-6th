# 1.Provide the prototype of function , definition and impelement function  ,and call the function
# 2. void igor()  float tofu(int)  double mpg(double ,double)  long summation(long * arr , int size)
     double doctor(const string)   void ofcourse(boss var)  char * plot(map * ptm)
# 3. viod fun(int arr[] , int size, int value){
    for(int i = 0; i < size, i++){
        arr[i] = value;
    }
}
# 4. viod fun(int * start, int * end, int value){
    for(int * p = start; i != end, start++){
        *p = value;
    }
}
# 5. double find(const double * arr , int size){
    double max = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}
# 6. Becuase the arguments pass to function is the copy of it'value ,modify with them will not change the original data.
# 7. the character array , string constant , pointer to string
# 8. int replace(char * str , char c1 , char c2){
        int number = 0;
        while(*str){
            if(!strcmp(str[i],c1)){
                str[i] = c2;
                number ++;
            }
            str++;
        } 
        return number;
}
# 9. p e
# 10.pass the glitz to function paraments as copy. pass the pointer to glitz, use reference.
# 11. int judge (int (*fun)(const * char))
# 12. void display(applcant app){
    cout << "name: "<< app.name << endl;
    for (int i = 0; i < sizeof(app.credit_ratings)/sizeof(int); i++)
        cout << app.credit_ratings[i];
}
      void display(const applcant * app){
    cout << "name: "<< app->name << endl;
    for (int i = 0; i < sizeof(app->credit_ratings)/sizeof(int); i++)
        cout << app->credit_ratingscredit_ratings[i];
}
# 13.  void (*p1)(applicatn *);
        p1 = f1;
        const char * (*p2)(const applicant *, const applicant *)
        p2 = f2;
        p1 ap[5]
        p2 (*pa)[10]
        ]