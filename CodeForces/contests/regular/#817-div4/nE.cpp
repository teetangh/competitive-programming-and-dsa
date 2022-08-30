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

// void _print(ll t) {cerr << t;}
// void _print(int t) {cerr << t;}
// void _print(string t) {cerr << t;}
// void _print(char t) {cerr << t;}
// void _print(ld t) {cerr << t;}
// void _print(double t) {cerr << t;}
// void _print(ull t) {cerr << t;}

// template <class T, class V> void _print(pair <T, V> p);
// template <class T> void _print(vector <T> v);
// template <class T> void _print(set <T> v);
// template <class T> void _print(multiset <T> v);
// template <class T, class V> void _print(map <T, V> v);
// template <class T , class V> void _print(multimap <T, V> v);
// template <class T> void _print(stack <T> v);
// template <class T> void _print(queue <T> v);
// template <class T> void _print(deque <T> v);
// template <class T> void _print(priority_queue <T> v);
// template <class T> void _print(unordered_set <T> v);
// template <class T> void _print(unordered_multiset <T> v);
// template <class T, class V> void _print(unordered_map <T, V> v);
// template <class T, class V> void _print(unordered_multimap <T, V> v);

// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(stack <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(queue <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(deque <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(priority_queue <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(unordered_multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(unordered_multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " ", _print(x), cerr << endl;
#else
#define debug(x)
#endif

class Rectangle
{
public:
    ulli hi, wi;
    Rectangle(ulli h, ulli w)
    {
        hi = h;
        wi = w;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
    freopen("xerror.txt", "w", stderr);  // for writing error messages to xerror.txt
#endif

    fastio();

    ulli tc;
    cin >> tc;

    while (tc--)
    {
        ulli n, q;
        cin >> n >> q;

        vector<Rectangle> me(n, Rectangle(0, 0));
        vector<pair<Rectangle, Rectangle>> them(q, pair<Rectangle, Rectangle>(Rectangle(0, 0), Rectangle(0, 0)));

        for (ulli i = 0; i < n; i++)
            cin >> me[i].hi >> me[i].wi;

        vector<ulli> overlappingArea(q, 0);
        for (ulli i = 0; i < q; i++)
        {
            cin >> them[i].first.hi >> them[i].first.wi >> them[i].second.hi >> them[i].second.wi;
            for (ulli j = 0; j < n; j++)
            {
                // if (me[j].hi < them[i].first.hi && me[j].wi < them[i].first.wi)
                //     overlappingArea[i] += me[j].hi * me[j].wi;
                // if (me[j].hi < them[i].second.hi && me[j].wi < them[i].second.wi)
                //     overlappingArea[i] += me[j].hi * me[j].wi;
                if ((them[i].first.hi < me[j].hi && me[j].hi < them[i].second.hi) &&
                    (them[i].first.wi < me[j].wi && me[j].wi < them[i].second.wi))
                    overlappingArea[i] += me[j].hi * me[j].wi;
            }

            cout << overlappingArea[i] << endl;
        }
    }

    return 0;
}
