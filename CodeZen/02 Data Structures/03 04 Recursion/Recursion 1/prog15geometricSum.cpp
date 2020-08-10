#include <iostream>
#include <math.h>
#include <iomanip>
// #include "solution.h"
using namespace std;

double geometricSum(int k)
{
    // Write your code here
    if (k == 0)
        return 1;

    else
        return (double)((1 / pow(2, k)) + geometricSum(--k));
}

int main()
{
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;
}
