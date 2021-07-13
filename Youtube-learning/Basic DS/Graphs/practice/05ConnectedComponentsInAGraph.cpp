// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define mod 1000000007
#define pb push_back
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

#define MAX 100001
vector<int> ar[MAX];
int vis[MAX];

void dfs(int node)
{
    vis[node] = 1;

    for (int child : ar[node])
        if (!vis[child])
            dfs(child);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int n, m, a, b;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
        cin >> a >> b, ar[a].pb(b), ar[b].pb(a);

    int cc = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i), cc++;
    }

    cout << cc << endl;
}
