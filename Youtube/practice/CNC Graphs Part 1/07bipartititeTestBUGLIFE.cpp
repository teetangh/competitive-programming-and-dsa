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

vi ar[2001];
int vis[2001];
int col[2001];

bool dfs(int node, int c)
{
    vis[node] = 1;
    col[node] = c;

    for (int child : ar[node])
    {
        if (!vis[child])
        {
            bool res = dfs(child, c ^ 1);
            if (res == false)
                return false;
        }

        else if (col[node] == col[child])
            return false;
    }

    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    int t, n, m, a, b;
    cin >> t;

    for (int tc = 1; tc <= t; tc++)
    {
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
            ar[i].clear(), vis[i] = 0;

        for (int i = 1; i <= m; i++)
            cin >> a >> b, ar[a].push_back(b), ar[b].push_back(a);

        bool flag = true;

        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                bool res = dfs(i, 0);
                if (res == false)
                    flag = false;
            }
        }

        cout << "Scenario #" << tc << ":" << endl;
        if (flag == false)
            cout << "Suspicious bugs found!" << endl;
        else
            cout << "No suspicious bugs found!" << endl;
    }
}
