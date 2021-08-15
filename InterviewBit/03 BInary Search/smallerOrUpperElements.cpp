// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int solve(vector<int> &A, int B)
{

    int low = 0;
    int high = A.size() - 1;

    int upperBound = -1;
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (A[mid] <= B)
        {
            upperBound = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return upperBound + 1;
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
        int B;
        cin >> B;
        cout << solve(A, B) << endl;
    }
}
