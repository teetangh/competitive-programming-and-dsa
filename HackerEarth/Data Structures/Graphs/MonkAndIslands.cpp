#include <bits/stdc++.h>

using namespace std;

#define MAX 10001
vector<int> ar[MAX];
int visited[MAX];
int dist[MAX];

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    dist[src] = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto child : ar[curr])
        {
            if (!visited[child])
            {
                q.push(child);
                dist[child] = dist[curr] + 1;
                visited[child] = 1;
            }
        }
    }
}

int main()
{
    int tc;
    cin >> tc;

    int v, e, a, b;
    while (tc--)
    {
        cin >> v >> e;

        for (int i = 0; i <= v; i++)
        {
            ar[i].clear();
            visited[i] = 0;
            dist[i] = 0;
        }

        for (int i = 1; i <= e; i++)
        {
            cin >> a >> b;
            ar[a].push_back(b);
            ar[b].push_back(a);
        }

        BFS(1);
        cout << dist[v] << endl;
    }
}