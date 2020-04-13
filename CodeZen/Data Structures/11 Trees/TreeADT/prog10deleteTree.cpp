#include <iostream>
#include <bits/stdc++.h>
#include "..\include\CNTree.hpp"
using namespace std;

void deleteTree(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
        deleteTree(root->children[i]);

    delete root;
}

// DO NOT USE THIS WITH OVERIDDEN DESTRUCTOR
int main(int argc, char const *argv[])
{
    TreeNode<int> *root = takeInputLevelWise();
    deleteTree(root);
    return 0;
}
