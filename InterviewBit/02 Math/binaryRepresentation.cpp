// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

string findDigitsInBinary(int A)
{
    if (A == 0 || A == 1)
        return {A + '0'};

    int temp = A;

    string result = "";
    while (temp != 1)
    {
        int x = temp / 2;
        int y = temp % 2;

        result.push_back(y + '0');
        temp = x;
    }

    result.push_back('1');
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc, n;
    cin >> tc;
    // cout << tc;

    while (tc--)
    {
        cin >> n;
        cout << findDigitsInBinary(n) << endl;
    }
}
