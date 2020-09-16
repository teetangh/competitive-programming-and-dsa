#include "PracticeBT.hpp"

bool hasPathSum(BinaryTreeNode<int> *root, int sum)
{
    if (root == NULL)
        return (sum == 0);

    else
    {
        bool ans = 0;

        int subSum = sum - root->data;

        if (subSum == 0 && !root->left && !root->right)
            return 1;

        if (root->left)
            ans = ans || hasPathSum(root->left, subSum);

        if (root->right)
            ans = ans || hasPathSum(root->right, subSum);

        return ans;
    }
}