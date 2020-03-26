#include <iostream>
using namespace std;
#include "include/FractionNew2.hpp"

int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);
    f1.print();

    Fraction f3 = ++(++f1);
    f1.print();
    f2.print();
    f3.print();

    Fraction f4 = f2++; //Nesting of post-increment operators gives error
    f2.print();
    f4.print();


}