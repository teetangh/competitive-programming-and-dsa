#include <iostream>
using namespace std;
// #include "solution.h"

void printPatt(int n)
{
    //write your code here
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            char startChar = ('A' + n - 1) - i + j;
            cout << startChar;
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    printPatt(n);
    return 0;
}
