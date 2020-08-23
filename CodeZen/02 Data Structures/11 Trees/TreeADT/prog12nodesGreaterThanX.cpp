#include <iostream>
#include <bits/stdc++.h>
#include "../include/CNTree.hpp"
using namespace std;

int nodesGreaterThanX(TreeNode<int> *root, int x)
{
    int ans;

    if (root->data > x)
        ans = 1;
    else
        ans = 0;

    for (int i = 0; i < root->children.size(); i++)
        ans += nodesGreaterThanX(root->children[i], x);

    return ans;
}

int main()
{
    int x;
    cin >> x;
    TreeNode<int> *root = takeInputLevelWise();
    cout << nodesGreaterThanX(root, x) << endl;
}