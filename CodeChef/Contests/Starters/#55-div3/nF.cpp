// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// Defines
#define endl '\n'
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

typedef unsigned long long int ulli;

ulli getSingleDigit(ulli M)
{
    ulli sum = 0;
    while (M)
    {
        sum += M % 10;
        M /= 10;
    }
    if (sum < 10)
        return sum;
    return getSingleDigit(sum);
}

int main()
{

    fastio();

    int tc;
    cin >> tc;

    ulli M, N;

    while (tc--)
    {
        cin >> N;
        M = (1 << N);
        cout << getSingleDigit(M) << endl;
    }

    return 0;
}
