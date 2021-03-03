// Includes
#include <bits/stdc++.h>
using namespace std;

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

    tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
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

    tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

int query(int *tree, int start, int end, int treeNode, int left, int right)
{

    // Completely outside given range
    if (start > right || end < left)
        return 0;

    // Completely inside given range
    if (start >= left && end <= right)
        return tree[treeNode];

    // Partially inside Partially outside
    int mid = (start + end) / 2;
    int ans1 = query(tree, start, mid, 2 * treeNode, left, right);
    int ans2 = query(tree, mid + 1, end, 2 * treeNode + 1, left, right);

    return ans1 + ans2;
}