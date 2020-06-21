#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
        return 1;

    int smallOutput = factorial(n - 1);
    int output = n * smallOutput;
    return output;
}

int main()
{
    int n;
    cin >> n;
    int output = factorial(n);

    cout << " Factorial is " << output << endl;
}