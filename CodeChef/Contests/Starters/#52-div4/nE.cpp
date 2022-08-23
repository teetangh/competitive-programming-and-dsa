// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

// Typedefs
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

bool isSafe(ulli i, ulli j, ulli M, ulli N)
{
    return (i >= 0 && i < M && j >= 0 && j < N);
}

bool dfs(pair<ulli, ulli> source, pair<ulli, ulli> destination, ulli movesLeft, ulli M, ulli N, vector<vector<bool>> &visited)
{
    visited[source.first][source.second] = true;

    if (source.first == destination.first &&
        source.second == destination.second &&
        movesLeft == 0)
        return true;

    if (movesLeft <= 0)
        return false;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++)
    {
        ulli x = source.first + dx[i];
        ulli y = source.second + dy[i];

        if (isSafe(x, y, M, N) && !visited[x][y])
        {
            if (dfs({x, y}, destination, movesLeft - 1, M, N, visited))
                return true;
        }
    }

    visited[source.first][source.second] = false;
    return false;
}

int solve(ulli M, ulli N, ulli X, ulli Y)
{
    vector<vector<bool>> visited(M, vector<bool>(N, false));

    if (dfs({0, 0}, {M - 1, N - 1}, X, M, N, visited))
        return 1;

    visited = vector<vector<bool>>(M, vector<bool>(N, false));

    if (dfs({M - 1, N - 1}, {0, 0}, Y, M, N, visited))
        return 1;

    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc;
    cin >> tc;

    while (tc--)
    {
        ulli M, N, X, Y;
        cin >> M >> N >> X >> Y;

        if (solve(M, N, X, Y))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
