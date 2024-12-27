#include<iostream>
using namespace std;

class Move 
{
private:
    double x;
    double y;
public:
    Move(double a = 0, double b = 0) : x(a), y(b) {}
    void showmove() const {cout << "x: " << x << ", y: " << y << endl;}
    Move add(const Move &m) const {return Move(x + m.x, y + m.y);}
    void reset(double a = 0, double b = 0) {x=a; y=b;}
};

int main()
{
    Move move1(3, 4);
    Move move2(1, 2);

    move1.showmove();
    move2.showmove();

    Move move3 = move1.add(move2);
    move3.showmove();

    move1.reset();
    move1.showmove();

    return 0;
}