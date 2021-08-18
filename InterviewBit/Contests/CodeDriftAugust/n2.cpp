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
#define mod 1000000007
#define INF 1000000000

void watchVec(vector<int> &A)
{
    cout << "A is ";
    for (auto ele : A)
        cout << ele << " ";
    cout << endl;
}

int solve(vector<int> &A)
{
    sort(A.begin(), A.end());
    // watchVec(A);
    // for (int i = 1; i < A.size(); i++)
    //     A[i] = A[i] - A[i - 1];
    // A[0] = 0;
    watchVec(A);

    int sum = 0;
    for (int i = 0; i < A.size(); i++)
        sum += A[i] + (A[i] - A[i - 1]);

    return sum - A[0];
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

// sample io
// 3

// 3
// 2 5 1

// 3
// 2 2 2

// 9
// 20 4 2 18 19 18 19 15 16
