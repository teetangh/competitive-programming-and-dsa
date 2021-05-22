// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 1; i <= n; i++)
#define INF 1000000000
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

// typedefs
typedef long long ll;
typedef long long int lli;

vi ar[1001];
int vis[1001], dist[1001];

void dfs(int node, int d)
{
    vis[node] = 1;
    dist[node] = d;

    for (auto &child : ar[node])
    {
        if (!vis[child])
            dfs(child, dist[node] + 1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int n, q, a, b;
    cin >> n;

    for (int i = 1; i <= n - 1; i++)
        cin >> a >> b, ar[a].push_back(b), ar[b].push_back(a);

    dfs(1, 0);

    cin >> q;

    int ans = 1, min_dist = INF;
    while (q--)
    {
        int girl_city;
        cin >> girl_city;

        if (dist[girl_city] < min_dist)
            min_dist = dist[girl_city], ans = girl_city;

        else if (dist[girl_city] == min_dist && girl_city < ans)
            ans = girl_city;
    }

    cout << ans;
}

// // Sample IO
// 6
// 1 2
// 1 3
// 1 4
// 2 5
// 2 6
// 4
// 5
// 6
// 3
// 4

// 3