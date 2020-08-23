#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include "../include/FINALBinaryTree.hpp"
using namespace std;

vector<int> *getRootToNodePath(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
        return NULL;

    if (root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int> *leftOutput = getRootToNodePath(root->left, data);
    if (leftOutput != NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int> *rightOutput = getRootToNodePath(root->right, data);
    if (rightOutput != NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else
        return NULL;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 
int main(int argc, char const *argv[])
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    vector<int> *output = getRootToNodePath(root, 8);
    for (int i = 0; i < output->size(); i++)
        cout << output->at(i) << endl;

    delete output;

    return 0;
}
