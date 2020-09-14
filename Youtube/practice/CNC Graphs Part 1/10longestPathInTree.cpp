#include <iostream>
#include <iomanip>
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

vector<int> ar[10001];
int vis[10001];
int maxD, maxNode;

void dfs(int node, int d)
{
    vis[node] = 1;
    if (d > maxD)
        maxD = d, maxNode = node;

    for (int child : ar[node])
    {
        if (vis[child] == 0)
            dfs(child, d + 1);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;
    int n, a, b;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
        cin >> a >> b, ar[b].push_back(a), ar[a].push_back(b);

    maxD = -1;
    dfs(1, 0);

    for (int i = 1; i <= n; i++)
        vis[i] = 0;

    maxD = -1;
    dfs(maxNode, 0);

    cout << maxD << endl;
}
