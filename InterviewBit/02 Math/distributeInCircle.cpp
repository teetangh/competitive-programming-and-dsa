// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int solve(int A, int B, int C)
{
    auto answer = (((A % B) + (C % B)) % B) - 1;
    if (answer < 0)
        return answer + B;
    else
        return answer;
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
    int A, B, C;

    while (tc--)
    {
        cin >> A >> B >> C;
        cout << solve(A, B, C) << endl;
    }
}
