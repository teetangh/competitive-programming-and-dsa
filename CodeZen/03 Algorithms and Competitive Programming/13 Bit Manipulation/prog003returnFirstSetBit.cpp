#include <iostream>
using namespace std;
// #include "Solution.h"

int returnFirstSetBit(int n)
{
    if (n == 0)
        return 0;

    int i;
    for (i = 0; n > 0; i++)
    {
        if ((n & 1) == 1)
            break;
        n >>= 1;
    }

    return (1 << i);
}

int main()
{
    int n;

    cin >> n;

    cout << returnFirstSetBit(n) << endl;

    return 0;
}
