#include <iostream>
using namespace std;
#include "include/FractionNew2.hpp"

int main()
{
    int i = 5, j = 3;
    (i += j) += j;
    cout << " i " << i << " j " << j << endl;

    Fraction f1(10, 3);
    Fraction f2(5, 2);
    (f1 += f2) += f2;
    f1.print();
    f2.print();
}