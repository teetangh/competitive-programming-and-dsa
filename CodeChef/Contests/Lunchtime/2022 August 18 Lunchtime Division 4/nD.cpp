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
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, size) for (int i = 1; i <= size; i++)

// Typedefs
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

ulli solve(vector<ulli> &arr)
{
    ulli B = 0;
    ulli A = 1;

    ulli tA = 0;
    ulli tB = 0;
    ulli totalTime = accumulate(arr.begin(), arr.end(), 0);

    vector<int> cumArr;
    cumArr.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++)
        cumArr.push_back(cumArr[i - 1] + arr[i]);

    ulli waitingTime = arr[0];
    while (tB < cumArr[cumArr.size() - 1])
    {
        tA++;
        if (B < A)
            tB++;
        else
            waitingTime++;

        if (A < arr.size() && tA == cumArr[A + 1])
            A = A + 1;
        if (B < arr.size() && tB == cumArr[B + 1])
            B = B + 1;
    }

    // cout << "total time " << totalTime << " waiting time " << waitingTime << endl;
    return totalTime + waitingTime;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    ulli tc;
    cin >> tc;

    while (tc--)
    {
        ulli size;
        cin >> size;

        vector<ulli> arr(size - 1);
        for (ulli i = 0; i < size - 1; i++)
            cin >> arr[i];

        cout << solve(arr) << endl;
    }

    return 0;
}
