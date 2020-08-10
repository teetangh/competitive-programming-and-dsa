#include <iostream>
#include <bits/stdc++.h>
#include "..\include\CNTree.hpp"
using namespace std;

int height(TreeNode<int> *root)
{
    // EDGE CASE NOT BASE CASE
    if (root == NULL)
        return 0;

    int currMaxHeight = 0;

    for (int i = 0; i < root->children.size(); i++)
    {
        int tempHeight = height(root->children[i]);
        if (tempHeight > currMaxHeight)
            currMaxHeight = tempHeight;
        else
            continue;
    }

    return 1 + currMaxHeight;
}
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    cout << height(root) << endl;
}