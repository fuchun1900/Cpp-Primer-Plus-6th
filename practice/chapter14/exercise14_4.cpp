#include "person.h"
#include <ctime>
#include <cstdlib>

Person::~Person() {}
void Person::Show() const {
    std::cout << "First Name: " << firstName << "\n"
              << "Last Name: " << lastName << "\n";
}
Gunslinger::~Gunslinger() {}
void Gunslinger::Show() const {
    Person::Show();
    std::cout << "Nick: " << nick << "\n";
}
PokerPlayer::~PokerPlayer() {}
Card PokerPlayer::Draw() const {
    Card card;
    srand(time(0)); // Seed the random number generator
    card.suite = static_cast<Card::SUIT>(rand() % 4); // Random suit
    card.number = rand() % 13 + 1; // Random number from 1 to 13
    return card;
}

int BadDude::Cdraw() const {
    Card card = PokerPlayer::Draw();
    return card.number; // Return the card number
}
double BadDude::Gdraw() const {
    // Simulate a gun draw, returning a random time in seconds
    return static_cast<double>(rand() % 100) / 10.0; // Random time between 0.0 and 9.9 seconds
}
BadDude::~BadDude() {}
/*
void BadDude::Show() const {
    Gunslinger::Show();
    PokerPlayer::Show();
    std::cout << "Gdraw time: " << Gdraw() << " seconds\n"
              << "Cdraw card number: " << Cdraw() << "\n";
}
              */

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    BadDude bd("John", "Doe", 5);
    bd.Show();

    Gunslinger gs("Jane", "Smith", 3);
    gs.Show();

    PokerPlayer pp("Alice", "Johnson");
    pp.Show();
    Card card = pp.Draw();
    std::cout << "Poker Player drew a card: "
              << "Suit: " << card.suite << ", Number: " << card.number << "\n";

    return 0;
}