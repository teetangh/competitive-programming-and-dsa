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
vector<int> primes;
int dist[MAX];
int visited[MAX];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    dist[src] = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto child : ar[curr])
        {
            if (!visited[child])
            {
                visited[child] = 1;
                dist[child] = dist[curr] + 1;
                q.push(child);
            }
        }
    }
}

bool isValid(int a, int b)
{
    int count = 0;

    while (a)
    {
        if ((a % 10) != (b % 10))
            count++;

        a /= 10, b /= 10;
    }

    if (count == 1)
        return true;
    else
        return false;
}

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}

void buildGraph()
{
    for (int i = 1000; i <= 9999; i++)
    {
        if (isPrime(i))
            primes.push_back(i);
    }

    for (int i = 0; i < primes.size(); i++)
    {
        for (int j = i + 1; j < primes.size(); j++)
        {
            int a = primes[i];
            int b = primes[j];

            if (isValid(a, b))
            {
                ar[a].push_back(b);
                ar[b].push_back(a);
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int t, a, b;
    cin >> t;

    buildGraph();

    while (t--)
    {
        cin >> a >> b;

        for (int i = 1000; i <= 9999; i++)
            dist[i] = -1, visited[i] = 0;

        bfs(a);

        if (dist[b] == -1)
            cout << "Impossible" << endl;
        else
            cout << dist[b] << endl;
    }
}
