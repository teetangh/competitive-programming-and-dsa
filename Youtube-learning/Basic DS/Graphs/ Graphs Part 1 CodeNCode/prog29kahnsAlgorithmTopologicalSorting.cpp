// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

#define MAX 100001

vector<int> ar[MAX];
vector<int> res;

int in[MAX];
int visited[MAX];
int low[MAX];
int timer;

void kahnsAlgorithm(int n)
{
    queue<int> q;
    for (int i = 0; i <= n; i++)
    {
        if (in[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int curr = q.front();
        res.push_back(curr);
        q.pop();

        for (auto node : ar[curr])
        {
            in[node]--;
            if (in[node] == 0)
                q.push(node);
        }
    }

    cout << " Topological Sorting : " << endl;
    for (auto ele : res)
        cout << ele << " ";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int n, m, x, y;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;

        ar[x].push_back(y);
        in[y]++;
    }

    kahnsAlgorithm(n);
}
