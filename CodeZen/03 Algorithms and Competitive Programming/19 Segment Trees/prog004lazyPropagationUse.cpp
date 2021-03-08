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

void updateSegmentTreeLazy(int *tree, int *lazy, int low, int high, int startRange, int endRange, int currPos, int increment)
{
    if (low > high)
        return;

    if (lazy[currPos] != 0)
    {
        tree[currPos] += lazy[currPos];
        if (low != high)
        {
            lazy[2 * currPos] += lazy[currPos];
            lazy[2 * currPos + 1] += lazy[currPos];
        }
        lazy[currPos] = 0;

        // No Overlap
        if (startRange > high || endRange < low)
            return;

        // Complete Overlap
        if (startRange <= low && high <= endRange)
        {
            tree[currPos] += increment;
            if (low != high)
            {
                lazy[2 * currPos] += increment;
                lazy[2 * currPos + 1] += increment;
            }
            return;
        }

        // Partial Overlap
        int mid = (low + high) / 2;
        updateSegmentTreeLazy(tree, lazy, low, mid, startRange, endRange, 2 * currPos, increment);
        updateSegmentTreeLazy(tree, lazy, mid + 1, high, startRange, endRange, 2 * currPos + 1, increment);

        tree[currPos] = min(tree[2 * currPos], tree[2 * currPos + 1]);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int arr[] = {1, 3, -2, 4};

    int *tree = new int[12];
    buildTree(arr, tree, 0, 3, 1);

    int *lazy = new int[12];
    updateSegmentTreeLazy(tree, lazy, 0, 3, 0, 3, 1, 3);
    updateSegmentTreeLazy(tree, lazy, 0, 3, 0, 1, 1, 2);

    cout << "Segment Tree" << endl;
    for (int i = 1; i < 12; i++)
        cout << tree[i] << " ";
    cout << endl;

    cout << "Lazy Tree" << endl;
    for (int i = 1; i < 12; i++)
        cout << lazy[i] << " ";
    cout << endl;
}
