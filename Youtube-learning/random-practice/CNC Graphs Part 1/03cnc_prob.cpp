#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

// Defines
#define REP(i, n) for (int i = 1; i <= v; i++)
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

vector<int> ar[10001];
int vis[10001];

void dfs(int node)
{
    vis[node] = 1;
    for (auto child : ar[node])
        if (!vis[child])
            dfs(child);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    int v, e, a, b;
    cin >> v >> e;

    for (int i = 1; i <= e; i++)
        cin >> a >> b, ar[a].push_back(b), ar[b].push_back(a);

    int cc = 0;

    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
            dfs(i), cc++;
    }

    cout << cc << endl;
}
