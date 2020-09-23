/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isValidBSTHelper(TreeNode *root, long int minValue, long int maxValue)
    {

        if (root == NULL)
            return true;

        if (root->val < minValue || root->val > maxValue)
            return false;

        return (isValidBSTHelper(root->left, minValue, (long int)root->val - 1) && isValidBSTHelper(root->right, (long int)root->val + 1, maxValue));
    }

    bool isValidBST(TreeNode *root)
    {

        return isValidBSTHelper(root, INT_MIN, INT_MAX);
    }
};