#include <iostream>
#include <bits/stdc++.h>
#include "..\include\FINALTree.hpp"
using namespace std;

void preorder(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
        preorder(root->children[i]);
}

void postorder(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    for (int i = 0; i < root->children.size(); i++)
        postorder(root->children[i]);
    cout << root->data << " ";
}

// Ready input
// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    preorder(root);
    postorder(root);
}