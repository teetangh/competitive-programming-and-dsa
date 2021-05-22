class Solution
{
    int sum = 0;

    void sumOfLeftLeaves(TreeNode *root, bool isLeft)
    {
        if (isLeft && !root->left && !root->right)
        {
            sum += root->val;
            return;
        }

        if (root->left)
            sumOfLeftLeaves(root->left, true);
        if (root->right)
            sumOfLeftLeaves(root->right, false);
    }

public:
    int sumOfLeaves(TreeNode *root)
    {
        if (!root)
            return 0;
    }
}