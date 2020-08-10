#include <iostream>
#include <bits/stdc++.h>
#include "..\include\FINALTree.hpp"
using namespace std;

int numNodes(TreeNode<int> *root)
{
    // EDGE CASE NOT BASE CASE
    if (root == NULL)
        return 0;

    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
        ans += numNodes(root->children[i]);
    return ans;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    cout << " Count of Number of nodes is " << numNodes(root) << endl;
}