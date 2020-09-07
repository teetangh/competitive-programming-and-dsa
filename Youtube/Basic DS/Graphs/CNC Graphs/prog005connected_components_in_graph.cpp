// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// typedefs
typedef long long ll;
typedef long long int lli;

vector<int> ar[100001];
int vis[100001];

void dfs(int node)
{
    vis[node] = 1;
    cout << "visited " << node << endl;
    for (int child : ar[node])
        if (!vis[child])
            dfs(child);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int v, e, a, b;
    cin >> v >> e;

    for (int i = 1; i <= e; i++)
        cin >> a >> b, ar[a].push_back(b), ar[b].push_back(a);

    int cc = 0;

    for (int i = 1; i <= v; i++)
        if (!vis[i])
            dfs(i), cc++;

    cout << cc << endl;
}
// // Sample IO
// 8 5
// 1 2
// 2 3
// 2 4
// 3 5
// 6 7

// visited 1
// visited 2
// visited 3
// visited 5
// visited 4
// visited 6
// visited 7
// visited 8
// 3
