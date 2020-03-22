#include <iostream>
// #include "solution.h"
using namespace std;

int multiplyNumbers(int m, int n)
{
    // Write your code here
    if (m == 0 || n == 0)
        return 0;
    else if (m == 1)
        return n;
    else if (n == 1)
        return m;
    else
        return n + multiplyNumbers(--m, n);
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}
