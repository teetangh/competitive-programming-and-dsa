#include <iostream>
#include <bits/stdc++.h>
#include "..\include\FINALTree.hpp"
using namespace std;

int numLeafNodes(TreeNode<int> *root)
{
    if (root->children.size() == 0)
        return 1;

    int totalLeaves = 0;

    for (int i = 0; i < root->children.size(); i++)
        totalLeaves += numLeafNodes(root->children[i]);

    return totalLeaves;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    cout << numLeafNodes(root) << endl;
}