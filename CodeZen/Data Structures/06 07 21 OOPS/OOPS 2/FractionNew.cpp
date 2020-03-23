#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction() {}

    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    // constant functions
    void print() const
    {
        cout << this->numerator << " / " << this->denominator << endl;
    }
    // constant functions
    int getNumerator() const
    {
        return numerator;
    }
    // constant functions
    int getDenominator() const
    {
        return denominator;
    }

    //  Doesn't qualify for constant functions
    void setNumerator(int numerator)
    {
        this->numerator = numerator;
    }
    // Doesn't qualify for constant functions
    void setDenominator(int denominator)
    {
        this->denominator = denominator;
    }

    // Doesn't qualify for constant functions
    void simplify()
    {
        int gcd = 1;
        int j = min(this->numerator, this->denominator);
        for (int i = 1; i <= j; i++)
        {
            if (this->numerator % i == 0 && this->denominator % i == 0)
                gcd = i;
        }
        this->numerator /= gcd;
        this->denominator /= gcd;
    }

    // Doesn't qualify for constant functions
    // f1 = f1 + f2
    void add(Fraction const &f2)
    {
        int lcm = denominator * f2.denominator;
        // cout << " DEBUG: lcm is " << lcm << endl;
        int x = lcm / denominator;
        // cout << " DEBUG: x is " << x << endl;
        int y = lcm / f2.denominator;
        // cout << " DEBUG: y is " << y << endl;

        int num = (x * numerator) + (y * f2.numerator);
        numerator = num;
        denominator = lcm;

        // this->simplify();
        simplify();
    }

    // Doesn't qualify for constant functions
    // f1=f1*f2
    void multiply(Fraction const &f2)
    {
        numerator *= f2.numerator;
        denominator *= f2.denominator;
        simplify();
    }

    // ~Fraction();
};
