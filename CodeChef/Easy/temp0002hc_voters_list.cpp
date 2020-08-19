#include <bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define mp make_pair
#define vi vector<ll>
#define pi pair<ll, ll>
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, end, start) for (ll i = end; i >= start; i--)
#define fa(it, graph) for (auto it = graph.begin(); it != graph.end(); it++)
#define endl "\n"
#define test  \
    ll t;     \
    cin >> t; \
    while (t--)
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define make(arr, n) ll *arr = new ll[n]
#define remove(arr) delete[] arr;
#define mod 1000000007
typedef long long ll;
#define max_size 100000000

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast;
    ll n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    ll total = n1 + n2 + n3;
    map<ll, ll> m;
    f(i, 0, total)
    {
        ll x;
        cin >> x;
        m[x]++;
    }
    vector<ll> result;
    fa(it, m)
    {
        if (it->second >= 2)
        {
            result.eb(it->first);
        }
    }
    cout << result.size() << endl;
    fa(it, result)
    {
        cout << *it << endl;
    }
    return 0;
}