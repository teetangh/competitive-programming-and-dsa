#include <iostream>
#include <bits/stdc++.h>
#include "..\include\CNTree.hpp"
using namespace std;

TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    TreeNode<int> *maxNode = root;

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *tempNode = maxDataNode(root->children[i]);
        if (tempNode > maxNode)
            maxNode = tempNode;
        else
            continue;
    }
    return maxNode;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    TreeNode<int> *ans = maxDataNode(root);
    if (root != NULL)
    {
        cout << ans->data;
    }
}