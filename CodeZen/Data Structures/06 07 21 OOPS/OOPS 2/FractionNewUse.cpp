#include <iostream>
using namespace std;
#include "FractionNew.cpp"

int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    // Constant Objects can only execute constant functions
    Fraction const f3; //Requires Default Constructor

    cout << f3.getNumerator() << " " << f3.getDenominator() << endl;
    // f3.setNumerator(10);   // Only Constant functions can be used
    return 0;
}
