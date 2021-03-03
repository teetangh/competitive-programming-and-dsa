// Includes
#include "include/segmentTree.hpp"
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *tree = new int[18]; // Need 2 * n - 1 size . // taking 1-index tree

    buildTree(arr, tree, 0, 8, 1);

    for (int i = 1; i < 18; i++)
        cout << tree[i] << endl;

    cout << "////////////////////////////////////////////" << endl;

    int arr2[] = {1, 2, 3, 4, 5};
    int *tree2 = new int[10]; // Need 2 * n - 1 size . // taking 1-index tree

    buildTree(arr, tree, 0, 4, 1);
    updateTree(arr, tree, 0, 4, 1, 2, 10);

    for (int i = 1; i < 10; i++)
        cout << tree[i] << endl;

    cout << "////////////////////////////////////////////" << endl;

    int ans = query(tree, 0, 4, 1, 2, 4);
    cout << "Sum between interval is " << ans << endl;
}
