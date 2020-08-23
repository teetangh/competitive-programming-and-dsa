#include <iostream>
#include <bits/stdc++.h>
#include "../include/CNTree.hpp"
using namespace std;

bool isIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
}

int main()
{
    TreeNode<int> *root1 = takeInputLevelWise();
    TreeNode<int> *root2 = takeInputLevelWise();
    if (isIdentical(root1, root2))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}