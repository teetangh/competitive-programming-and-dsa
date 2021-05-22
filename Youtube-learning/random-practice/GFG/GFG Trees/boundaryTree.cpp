#include "PracticeBT.hpp"
void printLeaves(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    printLeaves(root->left);
    if (!root->left && !root->right)
        cout << root->data;
    printLeaves(root->right);
}

void printBoundaryLeft(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    if (root->left)
    {
        cout << root->data;
        printBoundaryLeft(root->left);
    }
    else if (root->right)
    {
        cout << root->data;
        printBoundaryLeft(root->right);
    }
}

void printBoundaryRight(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    if (root->right)
    {
        printBoundaryRight(root->right);
        cout << root->data;
    }
    else if (root->left)
    {
        printBoundaryRight(root->left);
        cout << root->data;
    }
}

void printBoundaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    cout << root->data << endl;

    printBoundaryLeft(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    printBoundaryRight(root->right);
}