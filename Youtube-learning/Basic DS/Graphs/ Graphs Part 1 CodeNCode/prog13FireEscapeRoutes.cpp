// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define mod 1000000007
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

// Typedefs
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

#define MAX 100001
vector<int> ar[MAX];
int visited[MAX];
int cc_size;

void dfs(int node)
{
    visited[node] = 1;
    cc_size++;

    for (auto child : ar[node])
    {
        if (!visited[child])
            dfs(child);
    }
}

int main()
{
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#ifndef ONLINE_JUDGE
#endif

    fastio;

    int tc;
    cin >> tc;
    // cout << tc;

    int v, e, a, b;
    while (tc--)
    {
        cin >> v >> e;

        for (int i = 0; i <= v; i++)
        {
            ar[i].clear();
            visited[i] = 0;
        }

        for (int i = 1; i <= e; i++)
        {
            cin >> a >> b;
            ar[a].push_back(b);
            ar[b].push_back(a);
        }

        int count = 0;
        lli res = 1;

        for (int i = 1; i <= v; i++)
        {
            if (!visited[i])
            {
                cc_size = 0;
                dfs(i), count++;

                res = (res * cc_size) % mod;
            }
        }

        cout << count << " " << res << endl;
    }
}
