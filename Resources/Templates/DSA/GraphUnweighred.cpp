// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

// Policy Based Data Structures
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;



template <typename T>
class DSU
{
    vector<T> parent;
    vector<T> rank;

public:
    DSU(T n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (T i = 0; i < n; i++)
            parent[i] = i;
    }

    T find(T x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(T x, T y)
    {
        T s1 = find(x);
        T s2 = find(y);
        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
                swap(s1, s2);
            parent[s2] = s1;
            if (rank[s1] == rank[s2])
                rank[s1]++;
        }
    }
};

template <typename T>
class Graph
{
private:
    T V;
    vector<vector<T>> adj;
    vector<T> visited;
    vector<T> colors;
    bool isDirected;

public:
    Graph(T V)
    {
        this->V = V;
        adj.resize(V);
        visited.resize(V, 0);
        colors.resize(V, 0);
        isDirected = false;
    }

    void addEdge(T u, T v)
    {
        adj[u].push_back(v);
        if (!isDirected)
            adj[v].push_back(u);
    }

    void dfs(T node, vector<T> dfsOrder)
    {
        visited[node] = 1;
        dfsOrder.push_back(node);
        for (auto child : adj[node])
        {
            if (!visited[child])
                dfs(child, dfsOrder);
        }
    }

    void bfs(T node, vector<T> bfsOrder)
    {
        queue<T> q;
        q.push(node);
        visited[node] = 1;
        while (!q.empty())
        {
            T curr = q.front();
            q.pop();
            bfsOrder.push_back(curr);
            for (auto child : adj[curr])
            {
                if (!visited[child])
                {
                    q.push(child);
                    visited[child] = 1;
                }
            }
        }
    }

    void topoSort(T node, vector<T> topoOrder)
    {
        visited[node] = 1;
        for (auto child : adj[node])
        {
            if (!visited[child])
                topoSort(child, topoOrder);
        }
        topoOrder.push_back(node);
    }

    bool isBipartiteDfs(T node, T color)
    {
        visited[node] = 1;
        colors[node] = color;
        for (auto child : adj[node])
        {
            if (!visited[child])
            {
                if (!isBipartiteDfs(child, color ^ 1))
                    return false;
            }
            else
            {
                if (colors[node] == colors[child])
                    return false;
            }
        }
        return true;
    }

    bool isBipartiteBfs(T node)
    {
        queue<T> q;
        q.push(node);
        visited[node] = 1;
        colors[node] = 0;
        while (!q.empty())
        {
            T curr = q.front();
            q.pop();
            for (auto child : adj[curr])
            {
                if (!visited[child])
                {
                    q.push(child);
                    visited[child] = 1;
                    colors[child] = colors[curr] ^ 1;
                }
                else
                {
                    if (colors[child] == colors[curr])
                        return false;
                }
            }
        }
        return true;
    }

    // Dijkstra's Algorithm
    vector<T> dijkstra(T src)
    {
        vector<T> dist(V, T_MAX);
        dist[src] = 0;
        set<pair<T, T>> s;
        s.insert({0, src});
        while (!s.empty())
        {
            auto it = s.begin();
            T curr = it->second;
            T currDist = it->first;
            s.erase(it);
            for (auto child : adj[curr])
            {
                if (dist[child] > currDist + 1)
                {
                    auto f = s.find({dist[child], child});
                    if (f != s.end())
                        s.erase(f);
                    dist[child] = currDist + 1;
                    s.insert({dist[child], child});
                }
            }
        }
        return dist;
    }

    // Prim's Algorithm
    vector<T> prims(T src)
    {
        vector<T> dist(V, T_MAX);
        dist[src] = 0;
        set<pair<T, T>> s;
        s.insert({0, src});
        while (!s.empty())
        {
            auto it = s.begin();
            T curr = it->second;
            T currDist = it->first;
            s.erase(it);
            for (auto child : adj[curr])
            {
                if (dist[child] > currDist + 1)
                {
                    auto f = s.find({dist[child], child});
                    if (f != s.end())
                        s.erase(f);
                    dist[child] = currDist + 1;
                    s.insert({dist[child], child});
                }
            }
        }
        return dist;
    }

    // Kruskal's Algorithm
    T kruskal()
    {
        vector<pair<T, pair<T, T>>> edges;
        for (T i = 0; i < V; i++)
        {
            for (auto child : adj[i])
            {
                edges.push_back({1, {i, child}});
            }
        }
        sort(edges.begin(), edges.end());
        DSU dsu(V);
        T cost = 0;
        for (auto edge : edges)
        {
            T w = edge.first;
            T u = edge.second.first;
            T v = edge.second.second;
            if (dsu.find(u) != dsu.find(v))
            {
                cost += w;
                dsu.unite(u, v);
            }
        }
        return cost;
    }

    // Bellman Ford Algorithm
    vector<T> bellmanFord(T src)
    {
        vector<T> dist(V, T_MAX);
        dist[src] = 0;
        for (T i = 0; i < V - 1; i++)
        {
            for (T j = 0; j < V; j++)
            {
                for (auto child : adj[j])
                {
                    if (dist[child] > dist[j] + 1)
                        dist[child] = dist[j] + 1;
                }
            }
        }
        return dist;
    }

    // Floyd Warshall Algorithm
    vector<vector<T>> floydWarshall()
    {
        vector<vector<T>> dist(V, vector<T>(V, T_MAX));
        for (T i = 0; i < V; i++)
        {
            for (auto child : adj[i])
            {
                dist[i][child] = 1;
            }
        }
        for (T i = 0; i < V; i++)
        {
            for (T j = 0; j < V; j++)
            {
                for (T k = 0; k < V; k++)
                {
                    if (dist[j][k] > dist[j][i] + dist[i][k])
                        dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
        return dist;
    }

    // Articulation PoTs
    void dfsArticulation(T node, T parent, T &timer, vector<T> &Time, vector<T> &lowTime, vector<bool> &isArticulation)
    {
        visited[node] = 1;
        Time[node] = lowTime[node] = timer++;
        T children = 0;
        for (auto child : adj[node])
        {
            if (child == parent)
                continue;
            if (!visited[child])
            {
                dfsArticulation(child, node, timer, Time, lowTime, isArticulation);
                lowTime[node] = min(lowTime[node], lowTime[child]);
                if (lowTime[child] >= Time[node] && parent != -1)
                    isArticulation[node] = true;
                children++;
            }
            else
            {
                lowTime[node] = min(lowTime[node], Time[child]);
            }
        }
        if (parent == -1 && children > 1)
            isArticulation[node] = true;
    }

    vector<bool> articulationPoTs()
    {
        vector<bool> isArticulation(V, false);
        vector<T> Time(V, -1);
        vector<T> lowTime(V, -1);
        T timer = 0;
        for (T i = 0; i < V; i++)
        {
            if (!visited[i])
                dfsArticulation(i, -1, timer, Time, lowTime, isArticulation);
        }
        return isArticulation;
    }

    // Bridges
    void dfsBridges(T node, T parent, T &timer, vector<T> &Time, vector<T> &lowTime, vector<pair<T, T>> &bridges)
    {
        visited[node] = 1;
        Time[node] = lowTime[node] = timer++;
        for (auto child : adj[node])
        {
            if (child == parent)
                continue;
            if (!visited[child])
            {
                dfsBridges(child, node, timer, Time, lowTime, bridges);
                lowTime[node] = min(lowTime[node], lowTime[child]);
                if (lowTime[child] > Time[node])
                    bridges.push_back({node, child});
            }
            else
            {
                lowTime[node] = min(lowTime[node], Time[child]);
            }
        }
    }

    vector<pair<T, T>> bridges()
    {
        vector<pair<T, T>> bridges;
        vector<T> Time(V, -1);
        vector<T> lowTime(V, -1);
        T timer = 0;
        for (T i = 0; i < V; i++)
        {
            if (!visited[i])
                dfsBridges(i, -1, timer, Time, lowTime, bridges);
        }
        return bridges;
    }
};
