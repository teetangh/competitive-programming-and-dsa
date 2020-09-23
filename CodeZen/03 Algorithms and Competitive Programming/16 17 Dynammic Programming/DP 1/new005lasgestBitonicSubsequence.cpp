#include <iostream>
using namespace std;
// #include "solution.h"

int longestBitonicSubarray(int *input, int n)
{
}

int main()
{
    int n, input[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    cout << longestBitonicSubarray(input, n);
    return 0;
}
