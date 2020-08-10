#include <iostream>
// #include "solution.h"
using namespace std;

int sumOfDigits(int n)
{
    // Write your code here
    int x = n / 10;
    int y = n % 10;

    if (n >= 0 && n <= 9)
        return n;
    else
        return y + sumOfDigits(x);
}

int main()
{
    int n;
    cin >> n;
    cout << sumOfDigits(n) << endl;
}
