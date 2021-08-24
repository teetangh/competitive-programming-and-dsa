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
// #define MAX 100000
struct edge
{
    int a;
    int b;
    int w;
};

edge arr[100000];
int parent[10001];

bool comparator(edge a, edge b)
{
    if (a.w < b.w)
        return true;
    else
        return false;
}

int find(int a)
{
    if (parent[a] == -1)
        return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b)
{
    parent[a] = b;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int n, m, a, b, w;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        parent[i] = -1;

    for (int i = 0; i < m; i++)
        cin >> arr[i].a >> arr[i].b >> arr[i].w;

    int sum = 0;
    sort(arr, arr + m, comparator);

    for (int i = 0; i < m; i++)
    {
        a = find(arr[i].a);
        b = find(arr[i].b);

        if (a != b)
        {
            sum += arr[i].w;
            merge(a, b);
        }
    }

    cout << sum << endl;

    return 0;
}

// // Sample IO
// 4 5
// 1 2 7
// 1 4 6
// 4 2 9
// 4 3 8
// 2 3 6

// 19
