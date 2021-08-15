// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define watch1(x) cout << (#x) << " is " << (x) << endl
#define watch2(x, y) cout << (#x) << " is " << (x) << " " << (#y) << " is " << (y) << endl

int solve(vector<int> &A)
{

    // int minResult = INT_MAX;
    // for (int i = 0; i < A.size(); i++)
    // {
    //     int currentResult = 0;
    //     for (int j = i; j < A.size(); j++)
    //     {
    //         for (int k = i; k <= j; k++)
    //         {
    //             currentResult += (A[k] & A[i + j - k]);
    //         }
    //         if (currentResult < minResult)
    //             minResult = currentResult;
    //     }
    // }

    int maxPos = INT_MIN;
    int maxVal = INT_MIN;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] > maxVal)
        {
            maxPos = i;
            maxVal = A[i];
        }
    }

    int minResult = INT_MAX;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == maxVal)
            continue;
        else
        {
            if ((A[i] & maxVal) < minResult)
                minResult = A[i] & maxVal;
        }
    }

    return minResult;
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
        vector<int> A(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];
        cout << solve(A) << endl;
    }
}
