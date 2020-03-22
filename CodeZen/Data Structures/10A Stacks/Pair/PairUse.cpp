#include <iostream>
using namespace std;
#include "Pair.cpp"

int main()
{
    Pair<int, int> p1;
    Pair<double, double> p2;
    p1.setX(10);
    p1.setY(20);
    p2.setX(100.34);
    p2.setY(34.21);

    cout << p1.getX() << " " << p1.getY() << endl;
    cout << p2.getX() << " " << p2.getY() << endl;

    Pair<int, double> p3;
    p3.setX(100.34);
    p3.setY(100.34);
    cout << p3.getX() << " " << p3.getY() << endl;

    Pair<Pair<int, int>, int> p4;
    p4.setY(10);
    Pair<int, int> p5;
    p5.setX(5);
    p5.setY(16);
    p4.setX(p5);
    cout << p4.getX().getX() << " " << p4.getX().getY() << " " << p4.getY() << endl;
}
