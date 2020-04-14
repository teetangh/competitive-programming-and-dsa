#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include "..\include\CNTree.hpp"

TreeNode<int> *maxTreeNode(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (root1->data >= root2->data || root2 == NULL)
        return root1;
    else if (root1->data < root2->data || root1 == NULL)
        return root2;
}

pair<TreeNode<int> *, TreeNode<int> *> secondLargestHelper(TreeNode<int> *root, pair<TreeNode<int> *, TreeNode<int> *> maxANDmax2)
{
    pair<TreeNode<int> *, TreeNode<int> *> ans = maxANDmax2;

    for (int i = 0; i < root->children.size(); i++)
    {
        pair<TreeNode<int> *, TreeNode<int> *> temp = secondLargestHelper(root->children[i], maxANDmax2);

        TreeNode<int> *temporary = NULL;
        if (ans.second == NULL && temp.second == NULL)
        {
            if (ans.first <= temp.first)
            {
                temporary = ans.first;
                ans.first = temp.first;
                ans.second = temporary;
            }
            else
                ans.second = temp.first;
        }
        else if (ans.second == NULL && temp.second != NULL)
        {
            if (ans.first <= temp.first)
            {
                temporary = ans.first;
                ans.first = temp.first;

                ans.second = maxTreeNode(temporary, temp.second);
            }
            else
                ans.second = temp.first;
        }
        else if (ans.second != NULL && temp.second == NULL)
        {
            if (ans.first <= temp.first)
            {
                temporary = ans.first;
                ans.first = temp.first;

                ans.second = temporary;
            }
            else
                ans.second = maxTreeNode(ans.second, temp.first);
        }
        else if (ans.second != NULL && temp.second != NULL)
        {
            if (ans.first <= temp.first)
            {
                temporary = ans.first;
                ans.first = temp.first;

                ans.second = temporary;
            }
            else
                ans.second = temp.first;
        }
    }
    return ans;
}

TreeNode<int> *secondLargest(TreeNode<int> *root)
{
    pair<TreeNode<int> *, TreeNode<int> *> maxANDmax2;
    maxANDmax2.first = root;
    maxANDmax2.second = NULL;

    pair<TreeNode<int> *, TreeNode<int> *> finalAnswer = secondLargestHelper(root, maxANDmax2);

    return finalAnswer.second;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    TreeNode<int> *ans = secondLargest(root);
    if (ans == NULL)
    {
        cout << INT_MIN << endl;
    }
    else
    {
        cout << ans->data << endl;
    }
}
