// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

string solve(string &A, int n)
{

    int i = 0;
    int j = 0;

    while (A[i] != '\0' && A[j] != '\0')
    {
        while (A[j] == 'B' || A[j] == 'R')
            j++;

        i = j;
        while (A[j] == '?' && A[j] != '\0')
            j++;

        if (A[j] == '\0')
        {
            for (int k = i; k < j; k++)
            {
                if (A[k - 1] == 'R')
                    A[k] = 'B';
                else if (A[k - 1] == 'B')
                    A[k] = 'R';
                else
                    A[k] = 'R';
            }
            return A;
        }

        for (int k = j; k >= i; k--)
        {
            if (A[k] == 'R' || A[k] == 'B')
                continue;
            else if (A[k + 1] == 'B')
                A[k] = 'R';
            else if (A[k + 1] == 'R')
                A[k] = 'B';
        }
    }

    return A;
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

    while (tc--)
    {
        int n;
        cin >> n;
        string A;
        cin >> A;

        cout << solve(A, n) << endl;
    }
}
