#include <iostream>
using namespace std;

int factorial(int n)
{
    // Base Case
    if (n == 0)
        return 1;
    else
    {
        // Small Calculation(Induction Hypothesis)
        int smallOutput = factorial(n - 1);
        // Recursive Call(Induction Step)
        return n * smallOutput;
    }
}

int main()
{
    int n;
    cin >> n;
    int output = factorial(n);

    cout << " Factorial is " << output << endl;
}