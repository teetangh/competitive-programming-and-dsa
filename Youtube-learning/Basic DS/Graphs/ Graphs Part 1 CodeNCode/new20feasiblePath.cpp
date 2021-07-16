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
int dist[MAX];
int visited[MAX];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc, n, k, a, b;
    cin >> tc;

    while (tc--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            ar[i].clear(), visited[i] = 0;
    }
}
