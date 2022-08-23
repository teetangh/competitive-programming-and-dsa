// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

// Policy Based Data Structures
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define watch1(x) cout << (#x) << " is " << (x) << endl
#define watch2(x, y) cout << (#x) << " is " << (x) << " " << (#y) << " is " << (y) << endl
#define mod 1000000007
#define INF 1000000000
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, size) for (int i = 1; i <= size; i++)
// #define pb push_back
// #define ff first
// #define ss second
// #define pii pair<int, int>
// #define vi vector<int>
// #define vpii vector<pair<int, int>>

// Typedefs
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_less;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_less_equal;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_greater;
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_greater_equal;

int solve(vector<int> &arr, int k)
{
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
        vector<int> arr(size);
        for (int i = 0; i < size; i++)
            cin >> arr[i];

        int k;
        cin >> k;
        cout << solve(arr, k) << endl;
    }

    return 0;
}
