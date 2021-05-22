#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

// Defines
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// typedefs
typedef long long ll;
typedef long long int lli;

vector<int> ar[100001];
vector<int> primes;

int dist[100001], vis[100001];

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isValid(int a, int b)
{
    int cnt = 0;

    while (a > 0)
    {
        if (a % 10 != b % 10)
            cnt++;

        a /= 10, b /= 10;
    }
    if (cnt == 1)
        return true;
    else
        return false;
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
                ar[a].push_back(b), ar[b].push_back(a);
        }
    }
}

void bfs(int src)
{
    queue<int> q;
    q.push(src);

    dist[src] = 0;
    vis[src] = 1;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto child : ar[curr])
        {
            if (!vis[child])
            {
                vis[child] = 1;
                dist[child] = dist[curr] + 1;
                q.push(child);
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;
    int t, a, b;
    cin >> t;
    buildGraph();

    while (t--)
    {
        cin >> a >> b;

        for (int i = 1000; i <= 9999; i++)
            dist[i] = -1, vis[i] = 0;
        bfs(a);
        if (dist[b] == -1)
            cout << "Impossible" << endl;
        else
            cout << dist[b] << endl;
    }
}
