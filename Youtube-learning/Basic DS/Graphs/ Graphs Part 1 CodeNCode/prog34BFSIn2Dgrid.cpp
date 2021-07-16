// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int N, M;
#define MAX 1001
bool vis[MAX][MAX];
int dist[MAX][MAX];

bool isValid(int x, int y)
{
    if (x < 1 || x > N || y < 1 || y > M)
        return false;

    if (vis[x][y] == true)
        return false;

    return true;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int srcX, int srcY)
{
    queue<pair<int, int>> q;
    q.push({srcX, srcY});

    vis[srcX][srcY] = 1;
    dist[srcX][srcY] = 0;

    while (!q.empty())
    {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            if (isValid(currX + dx[i], currY + dy[i]))
            {
                int newX = currX + dx[i];
                int newY = currY + dy[i];

                q.push({newX, newY});
                vis[newX][newY] = 1;
                dist[newX][newY] = dist[currX][currY] + 1;
            }
        }
    }

    cout << " Distance Array is" << endl;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int x, y;
    cin >> N >> M;
    cin >> x >> y;

    bfs(x, y);
}

// // Sample IO 1
// 4 4

// 1 1

//  Distance Array is
// 0 1 2 3
// 1 2 3 4
// 2 3 4 5
// 3 4 5 6

// // Sample IO 2

// 9 9

// 5 5

//  Distance Array is
// 8 7 6 5 4 5 6 7 8
// 7 6 5 4 3 4 5 6 7
// 6 5 4 3 2 3 4 5 6
// 5 4 3 2 1 2 3 4 5
// 4 3 2 1 0 1 2 3 4
// 5 4 3 2 1 2 3 4 5
// 6 5 4 3 2 3 4 5 6
// 7 6 5 4 3 4 5 6 7
// 8 7 6 5 4 5 6 7 8
