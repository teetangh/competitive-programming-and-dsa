#include <iostream>
// #include <bits/stdc++.h>
#include "../include/CNBinaryTree.hpp"
using namespace std;

BinaryTreeNode<int> *getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength)
{
    // Write your code here
}

int main()
{
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++)
        cin >> post[i];
    for (int i = 0; i < size; i++)
        cin >> in[i];
    BinaryTreeNode<int> *root = getTreeFromPostorderAndInorder(post, size, in, size);
    printLevelATNewLine(root);
}
