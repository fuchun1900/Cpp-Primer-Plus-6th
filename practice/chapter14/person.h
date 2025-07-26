#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>

class Person {
private:
    std::string firstName;
    std::string lastName;
public:
    Person() : firstName("No name"), lastName("No name") {}
    Person(const std::string & fn, const std::string & ln)
        : firstName(fn), lastName(ln) {}
    virtual ~Person();
    void Show() const ;
};

class Gunslinger : virtual public Person {
private:
    int nick;
public:
    Gunslinger() : Person(), nick(0) {}
    Gunslinger(const std::string & fn, const std::string & ln, int n)
        : Person(fn, ln), nick(n) {}
    Gunslinger(const Person & p, int n)
        : Person(p), nick(n) {}
    virtual ~Gunslinger();
    void Show() const;  //隐藏虚基类的show方法
};

struct Card {
    enum SUIT { HEARTS, DIAMONDS, CLUBS, SPADES };
    SUIT suite; // 'H', 'D', 'C', 'S' for Hearts, Diamonds, Clubs, Spades
    int number; // 1-13 for Ace to King
};

class PokerPlayer : virtual public Person {
    public:
        PokerPlayer() : Person() {}
        PokerPlayer(const std::string & fn, const std::string & ln)
            : Person(fn, ln) {}
        PokerPlayer(const Person & p)
            : Person(p) {}
        virtual ~PokerPlayer();
        Card Draw() const;
};

class BadDude : public Gunslinger, public PokerPlayer {
public:
    BadDude() : Person() {}
    BadDude(const std::string & fn, const std::string & ln, int n)
        :Person(fn, ln) ,Gunslinger(fn, ln, n), PokerPlayer(fn, ln) {}
    BadDude(const Gunslinger & g, const PokerPlayer & p)
        : Person(g), Gunslinger(g), PokerPlayer(p) {}
    BadDude(const Person & p, int n)
        : Person(p), Gunslinger(p, n), PokerPlayer(p) {}
    virtual ~BadDude();
    //void Show() const;  
    double Gdraw() const;
    int Cdraw() const;

};

#endif // PERSON_H_