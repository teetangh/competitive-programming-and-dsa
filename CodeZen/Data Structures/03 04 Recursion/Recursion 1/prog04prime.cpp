#include <iostream>
using namespace std;
// #include "Solution.h"

void print(int n)
{
    if (n == 0)
    {
        // cout << n << " ";
        return;
    }

    print(n - 1);
    cout << n << " ";
}
int main()
{
    int n;
    cin >> n;

    print(n);
}
