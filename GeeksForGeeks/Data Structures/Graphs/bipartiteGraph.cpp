// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

    bool dfsUtil(int node, vector<int> adj[], vector<int> &visited, vector<int> &colors, int color)
    {
        visited[node] = 1;
        colors[node] = color;

        for (auto child : adj[node])
        {
            if (!visited[child])
            {
                auto answer = dfsUtil(child, adj, visited, colors, color ^ 1);
                if (answer == false)
                    return false;
            }
            else if (colors[node] == colors[child])
                return false;
        }

        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here
        vector<int> visited(V + 1, 0);
        vector<int> colors(V + 1, -1);

        auto answer = true;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                answer = dfsUtil(i, adj, visited, colors, 0);

            if (answer == false)
                return false;
        }
        return true;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends