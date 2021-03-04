// Includes
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
void buildTree(int *arr, int *tree, int start, int end, int treeNode)
{

    if (start == end)
    {
        tree[treeNode] = arr[start];
        return;
    }

    int mid = (start + end) / 2;

    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

    tree[treeNode] = min(tree[2 * treeNode], tree[2 * treeNode + 1]);
}

void updateTree(int *arr, int *tree, int start, int end, int treeNode, int idx, int value)
{
    if (start == end)
    {
        arr[idx] = value;
        tree[treeNode] = value;
        return;
    }
    int mid = (start + end) / 2;
    if (idx > mid)
        updateTree(arr, tree, mid + 1, end, 2 * treeNode + 1, idx, value);
    else
        updateTree(arr, tree, start, mid, 2 * treeNode, idx, value);

    tree[treeNode] = min(tree[2 * treeNode], tree[2 * treeNode + 1]);
}

int query(int *tree, int start, int end, int treeNode, int left, int right)
{

    // Completely outside given range
    if (start > right || end < left)
        return INT_MAX;

    // Completely inside given range
    if (start >= left && end <= right)
        return tree[treeNode];

    // Partially inside Partially outside
    int mid = (start + end) / 2;
    int ans1 = query(tree, start, mid, 2 * treeNode, left, right);
    int ans2 = query(tree, mid + 1, end, 2 * treeNode + 1, left, right);

    return min(ans1, ans2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int n, q;
    cin >> n >> q;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int *tree = new int[4 * n];
    for (int i = 0; i < 4 * n; i++)
        tree[i] = INT_MAX;

    buildTree(arr, tree, 0, n - 1, 1);

    // for (int i = 0; i < 2 * n; i++)
    //     cout << tree[i] << " ";
    // cout << endl;

    char operation;
    int a, b, answer;

    for (int i = 0; i < q; i++)
    {
        cin >> operation >> a >> b;
        // cout << "i is " << i << " " << operation << a << b;

        if (operation == 'u')
        {
            // printf("i is %d update \n", i);
            updateTree(arr, tree, 0, n - 1, 1, a - 1, b);
        }
        else if (operation == 'q')
        {
            // printf("i is %d query \n", i);
            answer = query(tree, 0, n - 1, 1, a - 1, b - 1);
            cout << answer << endl;
        }
    }
    return 0;
}

// // Sample IO
// 5 5
// 1 5 2 4 3
// q 1 5
// q 1 3
// q 3 5
// u 3 6
// q 1 5

// 1
// 1
// 2
// 1
