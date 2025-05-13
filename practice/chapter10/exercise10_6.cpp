# include <iostream>

class Move
{
private:
    double x; // horizontal distance moved
    double y; // vertical distance moved    
public:
    Move(double a = 0, double b = 0);
    void showmove() const; // show current x, y values
    Move add(const Move & m) const; // this function adds m to x, y
    void reset(double a = 0, double b = 0); // sets new x, y

};

Move::Move(double a, double b)
{
    x = a;
    y = b;
}

void Move::showmove() const
{
    std::cout << "x: " << x << ", y: " << y << std::endl;
}

Move Move::add(const Move & m) const
{
    Move result;
    result.x = x + m.x;
    result.y = y + m.y;
    return result;
}

void Move::reset(double a, double b)
{
    x = a;
    y = b;
}

int main()
{
    Move move1(3.0, 4.0);
    Move move2(1.0, 2.0);

    std::cout << "Move 1: ";
    move1.showmove();

    std::cout << "Move 2: ";
    move2.showmove();

    Move move3 = move1.add(move2);
    std::cout << "Move 3 (Move 1 + Move 2): ";
    move3.showmove();

    return 0;
}


