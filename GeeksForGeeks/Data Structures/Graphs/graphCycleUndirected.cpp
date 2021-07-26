// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    bool dfsUtil(int node, vector<int> adj[], vector<int> &visited, int parent)
    {
        visited[node] = 1;

        for (auto child : adj[node])
        {
            if (!visited[child])
            {
                auto answer = dfsUtil(child, adj, visited, node);
                if (answer == true)
                    return true;
            }
            else if (child != parent)
                return true;
        }

        return false;
    }

public:
    //Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        auto answer = false;
        vector<int> visited(V + 1, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                answer = dfsUtil(i, adj, visited, -1);
            if (answer == true)
                return true;
        }
        return false;
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
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends