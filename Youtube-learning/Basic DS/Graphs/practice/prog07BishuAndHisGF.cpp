// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

#define INF 10e9
#define MAX 1001
#define pb push_back

vector<int> ar[MAX];
int vis[MAX];
int dist[MAX];

void dfs(int node, int d)
{
    vis[node] = 1;
    dist[node] = d;

    for (auto child : ar[node])
    {
        if (!vis[child])
            dfs(child, dist[node] + 1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    int n, q, a, b;
    cin >> n;

    for (int i = 1; i <= n - 1; i++)
        cin >> a >> b, ar[a].pb(b), ar[b].pb(a);

    dfs(1, 0);

    int ans = -1, min_dist = INT_MAX;
    cin >> q;
    while (q--)
    {
        int girl_city;
        cin >> girl_city;

        if (dist[girl_city] < min_dist)
        {
            min_dist = dist[girl_city];
            ans = girl_city;
        }
        else if (dist[girl_city] == min_dist && girl_city < ans)
            ans = girl_city;
    }

    cout << ans << endl;
}
