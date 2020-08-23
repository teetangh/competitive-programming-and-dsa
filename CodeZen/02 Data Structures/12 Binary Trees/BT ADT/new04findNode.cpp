#include <iostream>
#include <bits/stdc++.h>
#include "../include/CNBinaryTree.hpp"
using namespace std;

bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int x;
    cin >> x;
    if (isNodePresent(root, x))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}
