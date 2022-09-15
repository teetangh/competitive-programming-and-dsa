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
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pair<int, int>>

// Typedefs
typedef long double ld;
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

// Policy Based Data Structures
// Can be less, less_equal, greater, greater_equal
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T , class V> void _print(multimap <T, V> v);
template <class T> void _print(stack <T> v);
template <class T> void _print(queue <T> v);
template <class T> void _print(deque <T> v);
template <class T> void _print(priority_queue <T> v);
template <class T> void _print(unordered_set <T> v);
template <class T> void _print(unordered_multiset <T> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T, class V> void _print(unordered_multimap <T, V> v);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(stack <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(queue <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(deque <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(priority_queue <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " ", _print(x), cerr << endl;
#else
#define debug(x)
#endif

void solve(int index, int currCost, int minCost, vector<int> &curr, vector<int> &arr, vector<vector<int>> &result)
{

    debug(result);
    if (index == arr.size() - 1)
    {
        
        if (currCost < minCost)
        {
            minCost = currCost;
            result.clear();
            result.push_back(curr);
        }
        else if (currCost == minCost)
        {
            result.push_back(curr);
        }
        return;
    }

    for (int i = index + 1; i < arr.size(); i++)
    {
        curr.push_back(arr[i]);
        solve(i, currCost + abs(arr[i] - arr[index]), minCost, curr, arr, result);
        curr.pop_back();
    }
}

pair<vector<int>, pair<int, int>> minJumps(vector<int> &arr)
{
    vector<vector<int>> result;
    vector<int> curr;
    int minCost = INT_MAX;
    solve(0, 0, minCost, curr, arr, result);
    vector<int> answer;
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i].size() >= answer.size())
            answer = result[i];
    }
    return {answer, {answer.size(), minCost}};
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
        string temp;
        cin >> temp;
        vector<int> arr;
        for (int i = 0; i < temp.size(); i++)
            arr.push_back(temp[i] - 'a');

        auto ans = minJumps(arr);
        cout << ans.ss.ff << " " << ans.ss.ss << endl;
        for (int i = 0; i < ans.ff.size(); i++)
            cout << ans.ff[i] << " ";

        cout << endl;
    }

    return 0;
}
