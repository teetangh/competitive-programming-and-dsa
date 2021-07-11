// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

// Typedefs
typedef long long int lli;

int isPower(int A)
{

    if (A == 1)
        return 1;
    else if (A == 2)
        return 0;

    for (int i = 2; i < A; i++)
    {
        int temp = A;

        int divCount = 0;
        while (temp % i == 0)
        {
            temp = temp / i;
            divCount++;
        }

        if (temp == 1 && divCount > 1)
            return 1;
    }

    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc;
    cin >> tc;
    // cout << tc;

    while (tc--)
    {
        int number;
        cin >> number;
        cout << isPower(number) << endl;
    }
}

// // Sample IO
// 2

// 4
// 1024000000

// // Output
// 1
// 1
