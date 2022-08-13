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

long long int solveHelper(vector<int> &A, int n, int k)
{
    if (n <= k)
        return 0;

    if (n == 3)
    {
        if (k == 0)
            return A[0] + A[2];
        else if (k == 1)
        {
            long long int temp1 = (A[0] + A[0]) + (A[1] + A[2]);
            long long int temp2 = (A[0] + A[1]) + (A[2] + A[2]);
            return max(temp1, temp2);
        }
        else if (k == 2)
        {
            return (2 * A[0]) + (2 * A[1]) + (2 * A[2]);
        }
    }

    long long int answer1 = solveHelper(A, n - 1, k);
    long long int answer2 = solveHelper(A, n - 1, k - 1) + (-A[n - 2] + A[n - 1]);

    return max(answer1, answer2);
}

int solve(vector<int> &A, int k)
{
    int n = A.size();
    auto answer = solveHelper(A, n, k);
    return answer;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc, k;
    cin >> tc;

    while (tc--)
    {
        int size;
        cin >> size;
        vector<int> A(size);
        for (int i = 0; i < size; i++)
            cin >> A[i];

        cin >> k;
        cout << solve(A, k) << endl;
    }

    return 0;
}
