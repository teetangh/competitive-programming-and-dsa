// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define MOD 10000000007
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

#define MAX 100001
typedef long long int lli;

vector<lli> ar[MAX];
lli visited[MAX];

lli dfs(lli node)
{
    lli count = 1;
    visited[node] = 1;

    for (auto child : ar[node])
    {
        if (!visited[child])
            count = (count + dfs(child));
    }
    return count;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    lli tc;
    cin >> tc;

    lli a, b;
    while (tc--)
    {
        lli v, e;
        cin >> v >> e;

        for (lli i = 0; i < MAX; i++)
        {
            ar[i].clear();
            visited[i] = 0;
        }

        for (lli i = 1; i <= e; i++)
        {
            cin >> a >> b;
            ar[a].push_back(b);
            ar[b].push_back(a);
        }

        lli cc_count = 0;
        lli captains = 1;
        for (lli i = 1; i <= v; i++)
        {
            if (!visited[i])
            {
                captains = ((captains % MOD) * (dfs(i) % MOD)) % MOD;
                cc_count++;
            }
        }

        cout << cc_count % MOD << " " << captains % MOD << endl;
    }
}
