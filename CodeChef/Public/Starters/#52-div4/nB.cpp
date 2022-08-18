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


ulli solve(vector<ulli> &testCases, string V)
{
    ulli ans = INT_MAX;
    for (int i = 0; i < testCases.size(); i++)
    {
        if (V[i] == '1')
            continue;
        else
            ans = min(ans, testCases[i]);
    }

    return ans;
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
        ulli n;
        cin >> n;

        vector<ulli> testCases;
        ulli temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            testCases.pb(temp);
        }

        string V;
        cin >> V;

        cout << solve(testCases, V) << endl;
    }

    return 0;
}
