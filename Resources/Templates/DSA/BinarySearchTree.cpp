template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T x) : val(x), left(NULL), right(NULL) {}

    void printTree(TreeNode *root)
    {
        if (root == NULL)
            return;
        printTree(root->left);
        cout << root->val << " ";
        printTree(root->right);
    }

    TreeNode *insertNode(TreeNode *root, T x)
    {
        if (root == NULL)
            return new TreeNode(x);
        if (x < root->val)
            root->left = insertNode(root->left, x);
        else
            root->right = insertNode(root->right, x);
        return root;
    }

    TreeNode *insertNode(TreeNode *root, vector<T> levelOrder)
    {
        for (int i = 0; i < levelOrder.size(); i++)
            root = insertNode(root, levelOrder[i]);
        return root;
    }

    TreeNode *removeNode(TreeNode *root, T x)
    {
        if (root == NULL)
            return NULL;
        if (x < root->val)
            root->left = removeNode(root->left, x);
        else if (x > root->val)
            root->right = removeNode(root->right, x);
        else
        {
            if (root->left == NULL)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                TreeNode *temp = root->right;
                while (temp->left != NULL)
                    temp = temp->left;
                root->val = temp->val;
                root->right = removeNode(root->right, temp->val);
            }
        }
        return root;
    }

    TreeNode *removeNode(TreeNode *root, vector<T> levelOrder)
    {
        for (int i = 0; i < levelOrder.size(); i++)
            root = removeNode(root, levelOrder[i]);
        return root;
    }

    TreeNode *searchNode(TreeNode *root, T x)
    {
        if (root == NULL)
            return NULL;
        if (x < root->val)
            return searchNode(root->left, x);
        else if (x > root->val)
            return searchNode(root->right, x);
        else
            return root;
    }

    TreeNode *searchNode(TreeNode *root, vector<T> levelOrder)
    {
        for (int i = 0; i < levelOrder.size(); i++)
            root = searchNode(root, levelOrder[i]);
        return root;
    }
};