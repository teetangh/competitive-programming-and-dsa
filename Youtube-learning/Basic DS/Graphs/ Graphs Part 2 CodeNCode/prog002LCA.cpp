// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int level[100000];
int parent[100000];

// Novice Approach
// T(n) = O(n)
// S(n) = O(n)
int LCA(int a, int b)
{
    if (level[b] < level[a])
        swap(a, b);

    int d = level[b] - level[a];

    while (d)
    {
        b = parent[b];
        d--;
    }

    if (a == b)
        return a;

    while (parent[a] != parent[b])
        a = parent[a], b = parent[b];

    // return parent[a]; // Both are now at the LCA
    return parent[b];
}