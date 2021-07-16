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

void dfs(int x, int y)
{
    vis[x][y] = 1;

    cout << x << " " << y << endl;

    // if (isValid(x - 1, y))
    //     dfs(x - 1, y); //up

    // if (isValid(x, y + 1))
    //     dfs(x, y + 1); // right

    // if (isValid(x + 1, y))
    //     dfs(x + 1, y); // down

    // if (isValid(x, y - 1))
    //     dfs(x, y - 1); //left

    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
            dfs(x + dx[i], y + dy[i]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    cin >> N >> M;

    dfs(1, 1);
}

// // Sample IO
// 3 3

// 1 1
// 1 2
// 1 3
// 2 3
// 3 3
// 3 2
// 2 2
// 2 1
// 3 1
