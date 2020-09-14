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
int vis[10001], dist[10001];

void BFS(int src)
{
    queue<int> q;
    q.push(src);

    vis[src] = 1;
    dist[src] = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto &child : ar[curr])
        {
            if (!vis[child])
            {
                q.push(child);
                dist[child] = dist[curr] + 1;
                vis[child] = 1;
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int t, n, m, a, b;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            ar[i].clear(), vis[i] = 0;

        while (m--)
            cin >> a >> b, ar[a].push_back(b), ar[b].push_back(a);

        BFS(1);

        cout << dist[n] << endl;
    }
}
