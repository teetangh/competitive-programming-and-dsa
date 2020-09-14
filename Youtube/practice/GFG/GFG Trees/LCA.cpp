#include "PracticeBT.hpp"

BinaryTreeNode<int> *findLCA(BinaryTreeNode<int> *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    auto leftLCA = findLCA(root->left, n1, n2);
    auto rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA && rightLCA)
        return root;

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}