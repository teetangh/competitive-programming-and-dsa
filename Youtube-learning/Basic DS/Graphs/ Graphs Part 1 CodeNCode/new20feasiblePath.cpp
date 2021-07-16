// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

#define MAX 1000001
vector<int> ar[MAX];

int dist[MAX];
int visited[MAX];
int cc[MAX];
int curr_cc;

void dfs(int node)
{
    visited[node] = 1;
    cc[node] = curr_cc;
    for (auto child : ar[node])
    {
        if (!visited[child])
            dfs(child);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc, n, k, a, b;
    string op;
    cin >> tc;

    while (tc--)
    {
        cin >> n >> k;

        curr_cc = 0;
        vector<pair<int, int>> edgeList;

        for (int i = 1; i <= n; i++)
            ar[i].clear(), visited[i] = 0;

        for (int i = 1; i <= k; i++)
        {
            cin >> a >> op >> b;

            if (op == "=")
                ar[a].push_back(b), ar[b].push_back(a);
            else
                edgeList.push_back({a, b}); // inserting as a pair
        }

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                curr_cc++;
                dfs(i);
            }
        }

        bool flag = true;
        for (int i = 0; i < edgeList.size(); i++)
        {
            a = edgeList[i].first;
            b = edgeList[i].second;

            if (cc[a] == cc[b])
            {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

// Sample Input
// 2
// 2 2
// 1 = 2
// 1 != 2
// 3 2
// 1 = 2
// 2 != 3
// Sample Output
// NO
// YES
