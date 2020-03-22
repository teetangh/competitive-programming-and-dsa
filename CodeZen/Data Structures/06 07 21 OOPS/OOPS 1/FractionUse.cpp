#include <iostream>
using namespace std;
#include "Fraction.cpp"

int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    cout << "after addition" << endl;
    f1.add(f2);
    f1.print();
    f2.print();

    cout << "after multiplication" << endl;
    f1.multiply(f2);
    f1.print();
    f2.print();

    return 0;
}
