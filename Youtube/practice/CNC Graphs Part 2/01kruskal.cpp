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

struct edge
{
    int a;
    int b;
    int W;
};

edge ar[100000];
int par[10001];

bool comp(edge e1, edge e2)
{
    return (e1.W < e2.W);
}

int find(int a)
{
    if (par[a] == -1)
        return a;

    return par[a] = find(par[a]);
}

void merge(int a, int b)
{
    par[a] = b;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int n, m, a, b;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        par[i] = -1;

    for (int i = 0; i < m; i++)
        cin >> ar[i].a >> ar[i].b >> ar[i].W;

    int sum = 0;
    sort(ar, ar + m, comp);

    for (int i = 0; i < m; i++)
    {
        a = find(ar[i].a);
        b = find(ar[i].b);

        if (a != b)
        {
            sum += ar[i].W;
            merge(a, b);
        }
    }
    cout << sum;
}

// Sample IO
// 4 5
// 1 2 7
// 1 4 6
// 4 2 9
// 4 3 8
// 2 3 6

// 19