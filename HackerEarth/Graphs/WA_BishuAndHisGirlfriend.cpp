// WRONG APPROACH

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// #define pb push_back
// #define MAX 100001

// vector<int> ar[MAX];
// int visited[MAX];
// int girls[MAX];

// int dfs(int node, int distance)
// {
//     visited[node] = 1;

//     if (girls[node] == 1)
//         return node;

//     int minCity = INT_MAX;
//     for (int i = 0; i < ar[node].size(); i++)
//     {
//         if (!visited[ar[node][i]])
//         {
//             int temp = dfs(ar[node][i], distance + 1);
//             if (temp < minCity && girls[temp] == 1)
//                 minCity = temp;
//         }
//     }

//     return minCity;
// }
// int main()
// {
//     int N;
//     cin >> N;

//     for (int i = 1; i <= N - 1; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         ar[u].pb(v);
//         ar[v].pb(u);
//     }

//     int Q, q;
//     cin >> Q;

//     for (int i = 0; i < Q; i++)
//     {
//         cin >> q;
//         girls[q] = 1;
//     }

//     int minCity = INT_MAX;
//     for (int i = 1; i <= N; i++)
//         minCity = min(minCity, dfs(i, 0));

//     cout << minCity << endl;
// }