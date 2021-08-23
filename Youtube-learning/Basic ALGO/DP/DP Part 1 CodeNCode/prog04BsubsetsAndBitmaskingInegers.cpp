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

vector<vector<int>> solve(vector<int> &A)
{
    int size = A.size();
    int subsetSize = (1 << size);

    vector<vector<int>> result;
    for (int subsetMask = 0; subsetMask < subsetSize; subsetMask++)
    {
        vector<int> subset;
        for (int i = 0; i < size; i++)
        {
            if ((subsetMask & (1 << i)) != 0)
                subset.push_back(A[i]);
        }
        result.push_back(subset);
    }

    return result;
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
        int size;
        cin >> size;
        vector<int> A(size);
        for (int i = 0; i < size; i++)
            cin >> A[i];

        auto answer = solve(A);

        for (auto ele : answer)
        {
            for (auto elee : ele)
            {
                cout << elee << "";
            }
            cout << endl;
        }
    }

    return 0;
}
