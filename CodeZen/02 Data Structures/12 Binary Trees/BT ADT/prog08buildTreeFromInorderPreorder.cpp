#include <iostream>
// #include <bits/stdc++.h>
#include "../include/FINALBinaryTree.hpp"
using namespace std;
// ASsumin no duplicates in the tree
BinaryTreeNode<int> *buildTreeHelper(int *in, int *pre, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
        return NULL;

    int rootData = pre[preS];

    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    // We know that:
    // lInE - lInS = lPreE - lPreS

    // LEFT VARIABLES
    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;

    // RIGHT VARIABLES
    int rInS = rootIndex + 1;
    int rInE = inE;
    int rPreS = lPreE + 1;
    int rPreE = preE;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
    return root;
}

BinaryTreeNode<int> *buildTree(int *in, int *pre, int size)
{
    return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}

BinaryTreeNode<int> *buildTreeCustomized(int *preorder, int preLenght, int *inorder, int inLength)
{
    // Write your code here
    return buildTreeHelper(inorder, preorder, 0, inLength - 1, 0, preLenght - 1);
}

int main(int argc, char const *argv[])
{
    int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};

    // Rest is same just chaning the input function
    BinaryTreeNode<int> *root = buildTree(in, pre, 9);
    printTree(root);
    return 0;
}
