#include <iostream>
using namespace std;

int turnOffFirstSetBit(int n)
{

    int safe_n = n;

    if (n == 0)
        return 0;

    int i;
    for (i = 0; n > 0; i++)
    {
        if ((n & 1) == 1)
            break;
        n >>= 1;
    }

    safe_n = safe_n & (~(1 << i));

    return safe_n;
}

int main()
{
    int n;

    cin >> n;

    cout << turnOffFirstSetBit(n) << endl;

    return 0;
}
