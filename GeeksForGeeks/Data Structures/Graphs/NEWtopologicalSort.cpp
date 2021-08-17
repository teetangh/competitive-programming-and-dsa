// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct Node
{
    int data;
    int indegree;

    Node(int data, int indegree)
    {
        this->data = data;
        this->indegree = indegree;
    }
};

struct compareInDegree
{
    bool operator()(Node *a, Node *b)
    {
        return a->indegree > b->indegree;
    }
};

class Solution
{

public:
    //Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        vector<int> indegree(V + 1, 0);
        // Create a map to store indegree of all vertices
        priority_queue<Node *, vector<Node *>, compareInDegree> pq;

        for (int i = 0; i < V; i++)
            for (auto ele : adj[i])
                indegree[ele]++;

        for (int i = 0; i < V; i++)
        {
            struct Node *newNode = new Node(i, indegree[i]);
            pq.push(newNode);
        }

        while (!pq.empty())
        {
            auto front = pq.top();
            pq.pop();

            for (auto ele : adj[front->data])
            {
                indegree[ele]--;
                if (indegree[ele] == 0)
                {
                    struct Node *newNode = new Node(ele, indegree[ele]);
                    pq.push(newNode);
                }
            }
        }
    }
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector<int> &res, vector<int> adj[])
{
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
} // } Driver Code Ends


// // NOT Sure sample io
// 4

// 4 5
// 2 0
// 0 1
// 1 3
// 3 1
// 1 0

// 4 4
// 0 1
// 1 2
// 2 3
// 3 3

// 6 5
// 5 3
// 3 1
// 1 2
// 2 4
// 4 0

// 11 11
// 7 0
// 0 4
// 4 5
// 5 6
// 6 8
// 8 9
// 9 3
// 3 2
// 2 1
// 1 10
// 4 6