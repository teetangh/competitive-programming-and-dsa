// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        queue<int> q;
        vector<int> visited(V + 1, 0);
        vector<int> result;

        q.push(0);
        result.push_back(0);
        visited[0] = 1;

        for (int i = 0; i < V; i++)
            sort(adj[i].begin(), adj[i].end());

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            for (auto child : adj[front])
            {
                if (!visited[child])
                {
                    visited[child] = 1;
                    q.push(child);
                    result.push_back(child);
                }
            }
        }
        return result;
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
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends