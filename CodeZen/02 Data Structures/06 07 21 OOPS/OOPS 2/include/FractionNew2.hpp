#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void print()
    {
        cout << this->numerator << " / " << this->denominator << endl;
    }

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

    // WITHOUT Operator Overloading
    // fNew = f1 + f2
    Fraction add(Fraction const &f2) const
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = (x * numerator) + (y * f2.numerator);
        // numerator = num;
        // denominator = lcm;

        Fraction fNew(num, lcm);
        fNew.simplify();
        return fNew;
    }

    //WITHOUT Operator Overloading
    // fNew = f1 * f2
    Fraction multiply(Fraction const &f2) const
    {
        int n = numerator * f2.numerator;
        int d = denominator * f2.denominator;
        Fraction fNew(n, d);
        fNew.simplify();
        return fNew;
    }
    // Operator Overloading
    // fNew = f1 + f2
    Fraction operator+(Fraction const &f2) const
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = (x * numerator) + (y * f2.numerator);
        // numerator = num;
        // denominator = lcm;

        Fraction fNew(num, lcm);
        fNew.simplify();
        return fNew;
    }

    // Operator Overloading
    // fNew = f1 * f2
    Fraction operator*(Fraction const &f2) const
    {
        int n = numerator * f2.numerator;
        int d = denominator * f2.denominator;
        Fraction fNew(n, d);
        fNew.simplify();
        return fNew;
    }

    // Operator Overloading
    bool operator==(Fraction const &f2) const
    {
        return (numerator == f2.numerator && denominator == f2.denominator);
    }

    // pre-increment
    // return by reference so that temporary buffer is not created
    // and also that nesting increment operators work
    Fraction &operator++()
    {
        numerator = numerator + denominator;
        simplify();
        return *this;
    }

    // Post-increment
    Fraction operator++(int) // (int) distinguishes it from pre-increment
    {
        Fraction fNew(numerator, denominator);
        numerator = numerator + denominator;
        simplify();
        fNew.simplify();
        return fNew;
    }

    Fraction &operator+=(Fraction const &f2)
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = (x * numerator) + (y * f2.numerator);
        numerator = num;
        denominator = lcm;

        simplify();
        return *this;
    }
};
