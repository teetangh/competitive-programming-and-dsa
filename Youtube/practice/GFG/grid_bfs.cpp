#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dist[1001][1001];
int N, M;
int vis[1001][1001];

bool isValid(int x, int y)
{
    if (x < 1 || x > N || y < 1 || y > M)
        return false;

    if (vis[x][y] == 1)
        return false;

    return true;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void BFS(int srcX, int srcY)
{
    queue<pair<int, int>> q;
    q.push({srcX, srcY});
    dist[srcX][srcY] = 0;
    vis[srcX][srcY] = 1;

    while (!q.empty())
    {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
            if (isValid(currX + dx[i], currY + dy[i]))
            {
                int newX = currX + dx[i];
                int newY = currY + dy[i];

                dist[newX][newY] = dist[currX][currY] + 1;
                vis[newX][newY] = 1;

                q.push({newX, newY});
            }
    }

    cout << "Distance Array \n";
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    int x, y;
    cin >> N >> M;
    cin >> x >> y;

    BFS(x, y);
    return 0;
}
