#include <iostream>
#include <bits/stdc++.h>
#include "..\include\CNTree.hpp"
using namespace std;

TreeNode<int> *nextLargerElement(TreeNode<int> *root, int n)
{
    TreeNode<int> *ans = NULL;

    if (root->data > n)
    {
        ans = root;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *temp = nextLargerElement(root->children[i], n);
        if (ans == NULL)
            ans = temp;
        else if (temp != NULL && temp->data > n && temp->data < ans->data)
            ans = temp;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    TreeNode<int> *root = takeInputLevelWise();
    TreeNode<int> *ans = nextLargerElement(root, n);
    if (ans != NULL)
    {
        cout << ans->data << endl;
    }
    else
    {
        cout << INT_MIN << endl;
    }
}
