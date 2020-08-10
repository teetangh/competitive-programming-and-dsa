#include <iostream>
// #include "solution.h"
using namespace std;

int countZeros(int n)
{
    // Write your code here
    if (n >= 1 && n <= 9)
        return 0;

    int x = n / 10;
    int y = n % 10;

    if (y == 0)
        return (1 + countZeros(x));
    else
        return (0 + countZeros(x));
}

int main()
{
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
