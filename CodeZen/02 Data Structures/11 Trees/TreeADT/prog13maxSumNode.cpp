#include <iostream>
#include <bits/stdc++.h>
#include "../include/CNTree.hpp"
using namespace std;

// Can use pairs to solve the Recursions problem as well
// Try it later
TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    TreeNode<int> *ans = root;
    int sum = root->data;

    for (int i = 0; i < root->children.size(); i++)
        sum += root->children[i]->data;

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *x = maxSumNode(root->children[i]);
        int xSum = x->data;

        for (int j = 0; j < x->children.size(); j++)
            xSum += x->children[j]->data;

        if (xSum > sum)
        {
            ans = x;
            sum = xSum;
        }
    }
    return ans;
}
// TreeNode<int> *maxSumNode(TreeNode<int> *root)
// {
//     TreeNode<int> *ans = root;
//     int sum = root->data;

//     for (int i = 0; i < root->children.size(); i++)
//         sum += root->children[i]->data;

//     for (int i = 0; i < root->children.size(); i++)
//     {
//         TreeNode<int> *x = root->children[i];
//         int xSum = x->data;

//         for (int j = 0; j < x->children.size(); j++)
//             xSum += x->children[j]->data;

//         if (sum > xSum)
//         {
//             ans = x;
//             sum = xSum;
//         }
//     }
//     return ans;
// }

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    TreeNode<int> *ans = maxSumNode(root);
    if (ans != NULL)
    {
        cout << ans->data << endl;
    }
}
