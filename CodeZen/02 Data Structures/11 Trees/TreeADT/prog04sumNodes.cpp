#include <iostream>
#include <bits/stdc++.h>
#include "..\include\CNTree.hpp"
using namespace std;

int sumOfNodes(TreeNode<int> *root)
{
    // EDGE CASE NOT BASE CASE
    if (root == NULL)
        return 0;
    int sum = root->data;

    for (int i = 0; i < root->children.size(); i++)
    {
        sum += sumOfNodes(root->children[i]);
    }
    return sum;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    cout << sumOfNodes(root) << endl;
}