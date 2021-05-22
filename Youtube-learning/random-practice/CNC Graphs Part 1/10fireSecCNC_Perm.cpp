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

vi ar[100001];
int vis[100001];
int cc_size;

void dfs(int node)
{
    vis[node] = 1;
    cc_size++;

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

    fastio;
    int t, n, m, a, b;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            vis[i] = 0, ar[i].clear();

        for (int i = 1; i <= m; i++)
            cin >> a >> b, ar[a].pb(b), ar[b].pb(a);

        int cnt = 0;
        lli res = 1;

        for (int i = 1; i <= n; i++)
            if (!vis[i])
            {
                cc_size = 0;
                dfs(i), cnt++;
                res = (res * cc_size) % mod;
            }
        cout << cnt << " " << res << endl;
    }
}
