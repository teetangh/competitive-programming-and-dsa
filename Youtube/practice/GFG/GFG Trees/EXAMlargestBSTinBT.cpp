// #include "PracticeBT.hpp"

// struct Info
// {
//     int size;
//     int max;
//     int min;
//     int ans;

//     bool isBST;
// };

// Info largestBST(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//         return {0, INT_MIN, INT_MAX, 0, true};
//     if (root->left == NULL && root->right == NULL)
//         return {1, root->data, root->data, true};

//     Info l = largestBST(root->left);
//     Info r = largestBST(root->right);

//     Info ret;
//     ret.size = (1 + l.sz + r.sz);

//     if (l.isBST && r.isBST && l.max < root->data && r.min < root->data)
//     {
//         ret.min = min(l.min, min(r.min, root->data));
//         ret.max = max(r.max, max(l.max, root->data));

//         ret.ans = ret.size;
//         ret.isBST = true;
//     }

//     ret.ans = max(l.ans, r.ans);
//     ret.isBST = true;
//     return ret;
// }

#include "PracticeBT.hpp"

struct Info
{
    int size;
    int min;
    int max;
    int ans;

    bool isBST;
};

Info largestBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return {0, INT_MIN, INT_MAX, 0, true};

    if (root->left == NULL && root->right == NULL)
        return {1, root->data, root->data, 1, true};

    auto l = largestBST(root->left);
    auto r = largestBST(root->right);

    Info ret;
    ret.size = 1 + l.size + r.size;

    if (l.isBST && r.isBST && l.max < root->data && r.min > root->data)
    {
        ret.min = min(l.min, min(r.min, root->data));
        ret.max = max(l.max, max(l.max, root->data));

        ret.ans = ret.size;
        ret.isBST = true;

        return ret;
    }

    ret.ans = max(l.ans, r.ans);
    ret.isBST = false;

    return ret;
}