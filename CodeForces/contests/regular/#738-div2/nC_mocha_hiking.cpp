// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define watch1(x) cout << (#x) << " is " << (x) << endl
#define watch2(x, y) cout << (#x) << " is " << (x) << " " << (#y) << " is " << (y) << endl

#define MAX 10001

void dfsUtil(int node, vector<int> adj[], vector<int> &visited, vector<int> &result)
{
    visited[node] = 1;
    result.push_back(node);

    for (auto child : adj[node])
    {
        if (!visited[child])
            dfsUtil(child, adj, visited, result);
    }
}

void solve(vector<int> &A, int n)
{

    vector<int> adj[n + 2];
    vector<int> visited(n + 2, 0);
    vector<int> result;

    for (int i = 1; i <= n - 1; i++)
        adj[i].push_back(i + 1);

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == 0)
            adj[i + 1].push_back(n + 1);
        else if (A[i] == 1)
            adj[n + 1].push_back(i + 1);
    }

    int cc_count = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        if (!visited[i])
        {
            if (cc_count >= 1)
            {
                result = {-1};
            }
            dfsUtil(i, adj, visited, result), cc_count++;
        }
    }

    for (auto ele : result)
        cout << ele << " ";
    cout << endl;
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
        int size;
        cin >> size;
        vector<int> A(size);
        for (int i = 0; i < size; i++)
            cin >> A[i];
        solve(A, size);
    }
}
