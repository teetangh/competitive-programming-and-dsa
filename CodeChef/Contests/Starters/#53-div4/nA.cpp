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
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define watch1(x) cout << (#x) << " is " << (x) << endl
#define watch2(x, y) cout << (#x) << " is " << (x) << " " << (#y) << " is " << (y) << endl
#define MOD 1000000007
#define INF 1e18
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, size) for (int i = 1; i <= size; i++)
// #define pb push_back
// #define ff first
// #define ss second
// #define pii pair<int, int>
// #define vi vector<int>
// #define vpii vector<pair<int, int>>

// Typedefs
typedef long double ld;
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

// Policy Based Data Structures
// Can be less, less_equal, greater, greater_equal
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// void _print(ll t) {cerr << t;}
// void _print(int t) {cerr << t;}
// void _print(string t) {cerr << t;}
// void _print(char t) {cerr << t;}
// void _print(lld t) {cerr << t;}
// void _print(double t) {cerr << t;}
// void _print(ull t) {cerr << t;}

// template <class T, class V> void _print(pair <T, V> p);
// template <class T> void _print(vector <T> v);
// template <class T> void _print(set <T> v);
// template <class T, class V> void _print(map <T, V> v);
// template <class T> void _print(multiset <T> v);
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " ", _print(x), cerr << endl;
#else
#define debug(x)
#endif

int solve(vector<int> &arr, int k)
{
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
    freopen("xerror.txt", "w", stderr);  // for writing error messages to xerror.txt
#endif

    fastio();

    int tc;
    cin >> tc;

    while (tc--)
    {
        ulli dist;
        cin >> dist;
        ulli value = 10 * dist;
        if (value < 3000)
            cout << "3000" << endl;
        else
            cout << value << endl;
    }

    return 0;
}
