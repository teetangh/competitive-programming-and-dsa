#include "PracticeBT.hpp"

BinaryTreeNode<int> *removeOutsideRange(BinaryTreeNode<int> *root, int min, int max)
{
    if (root == NULL)
        return NULL;

    root->left = removeOutsideRange(root->left, min, max);
    root->left = removeOutsideRange(root->left, min, max);

    if (root->data < min)
    {
        auto lchild = root->right;
        delete root;
        return lchild;
    }
    if (root->data > max)
    {
        auto rchild = root->left;
        delete root;
        return rchild;
    }

    return root;
}