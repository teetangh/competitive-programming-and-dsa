// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

// Typedefs
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

#define MAX 10001

vector<int> ar[MAX];
int vis[MAX];
int dist[MAX];

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

        for (auto child : ar[curr])
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
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc, n, m, a, b;
    cin >> tc;

    while (tc--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            ar[i].clear();
            vis[i] = 0;
        }

        while (m--)
            cin >> a >> b, ar[a].push_back(b), ar[b].push_back(a);

        BFS(1);

        cout << dist[n] << endl;
    }
}
