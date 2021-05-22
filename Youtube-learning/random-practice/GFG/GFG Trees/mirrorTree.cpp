#include "PracticeBT.hpp"

void mirrorTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    else
    {
        mirrorTree(root->left);
        mirrorTree(root->right);

        auto temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}