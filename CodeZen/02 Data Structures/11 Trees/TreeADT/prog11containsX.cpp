#include <iostream>
#include <bits/stdc++.h>
#include "../include/CNTree.hpp"
using namespace std;

bool containsX(TreeNode<int> *root, int x)
{
    bool answer = false;

    if (root->data == x)
        return true;

    for (int i = 0; i < root->children.size(); i++)
    {
        bool tempAns = containsX(root->children[i], x);
        if (tempAns == true)
            return true;
    }

    return answer;
}

int main()
{
    int x;
    cin >> x;
    TreeNode<int> *root = takeInputLevelWise();
    if (containsX(root, x))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}