#include <iostream>
#include <bits/stdc++.h>
#include "../include/FINALBinaryTree.hpp"
using namespace std;

void inOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main(int argc, char const *argv[])
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTree(root);

    cout << "\n INORDER TRAVERSAL\n ";
    inOrder(root);
    cout << "\n PREORDER TRAVERSAL\n ";
    preOrder(root);
    cout << "\n POSTORDER TRAVERSAL\n ";
    postOrder(root);
    delete root;
    return 0;
}