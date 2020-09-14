#include "PracticeBT.hpp"
#include <climits>

int isBST(BinaryTreeNode<int> *root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int isBSTUtil(BinaryTreeNode<int> *root, int min, int max)
{
    if (root == NULL)
        return 1;
    if (root->data < min || root->data > max)
        return 0;

    return isBSTUtil(root->left, min, root->data - 1) && isBSTUtil(root->right, root->data + 1, max);
}