#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include "..\include\CNTree.hpp"

void replaceWithDepthValueHelper(pair<TreeNode<int> *, int> root)
{
    (root.first)->data = root.second;

    int nextLevel = root.second + 1;

    for (int i = 0; i < (root.first)->children.size(); i++)
        replaceWithDepthValueHelper(std::make_pair((root.first)->children[i], nextLevel));
}

void replaceWithDepthValue(TreeNode<int> *root)
{
    pair<TreeNode<int> *, int> ans;
    ans.first = root;
    ans.second = 0;

    replaceWithDepthValueHelper(ans);
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    replaceWithDepthValue(root);
    printLevelATNewLine(root);
}
