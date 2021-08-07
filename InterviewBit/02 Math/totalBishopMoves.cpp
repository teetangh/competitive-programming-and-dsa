// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

bool isValid(int i, int j)
{
    if (i <= 0 || i > 8)
        return false;

    if (j <= 0 || j > 8)
        return false;

    return true;
}

int solve(int x, int y)
{

    int i = 0;
    int j = 0;

    i = x, j = y;
    int count = 0;

    while (isValid(i, j))
    {
        i--, j++;
        count++;
    }

    i = x, j = y;
    while (isValid(i, j))
    {
        i--, j--;
        count++;
    }

    i = x, j = y;
    while (isValid(i, j))
    {
        i++, j++;
        count++;
    }

    i = x, j = y;
    while (isValid(i, j))
    {
        i++, j--;
        count++;
    }

    return count - 4;
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
        int a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
}
