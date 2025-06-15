#include <iostream>
#include <cstring>

class Cow{
private:
    char name[20];
    char * hobby;
    double weight;
public:
    Cow();
    Cow(const char * nm, const char * ho, double wt);
    Cow(const Cow & c);
    ~Cow();
    Cow & operator=(const Cow & c);
    void ShowCow() const;
};

Cow::Cow(){
    name[0] = '\0';
    hobby = new char[1]();
    weight = 0;
}

Cow::Cow(const char * nm, const char * ho, double wt){
    strncpy(name, nm, 19);
    name[19] = '\0';
    hobby = new char[strlen(ho) + 1];
    strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow & c){
    strncpy(name, c.name, 19);
    name[19] = '\0';
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}
Cow::~Cow(){
    delete [] hobby;
}
Cow & Cow::operator=(const Cow & c){
    if (this == &c)
        return *this;
    strncpy(name,c.name,19);
    name[19] = '\0';
    delete []hobby;
    hobby = new char[strlen(c.hobby) + 1];
    strncpy(hobby, c.hobby, strlen(c.hobby) + 1);
    hobby[strlen(c.hobby)] = '\0';
    weight = c.weight;
    return *this;
}
void Cow::ShowCow() const{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Hobby: " << hobby << std::endl;
    std::cout << "Weight: " << weight << std::endl;
}

int main(){
    Cow cow1("Bessie", "Grazing", 1500);
    Cow cow2 = cow1; // Copy constructor
    Cow cow3;
    cow3 = cow1; // Assignment operator
    cow1.ShowCow();
    cow2.ShowCow();
    cow3.ShowCow();
    return 0;
}