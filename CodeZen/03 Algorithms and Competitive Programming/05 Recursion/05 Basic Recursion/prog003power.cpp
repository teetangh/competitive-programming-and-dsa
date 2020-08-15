#include <iostream>
// #include "Solution.h"
using namespace std;

int power(int x, int n)
{

    if (x == 0)
        return 0;
    if (x == 1 || n == 0)
        return 1;

    if (n == 1)
        return x;

    return x * power(x, n - 1);
}

int main()
{
    int x, n;
    cin >> x >> n;

    cout << power(x, n) << endl;
}
