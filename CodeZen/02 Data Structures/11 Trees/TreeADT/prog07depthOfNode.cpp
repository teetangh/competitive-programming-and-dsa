#include <iostream>
#include <bits/stdc++.h>
#include "../include/FINALTree.hpp"
using namespace std;

void printAtLevelK(TreeNode<int> *root, int k)
{
    // EDGE CASE NOT BASE CASE
    if (root == NULL)
        return;

    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
        printAtLevelK(root->children[i], k - 1);
}

int main(int argc, char const *argv[])
{
    TreeNode<int> *root = takeInputLevelWise();

    cout << " printAtLevelK "
         << " Enter K " << endl;
    int K;
    cin >> K;
    
    cout << " Nodes at LevelK :" << endl;
    printAtLevelK(root, K);
    
    return 0;
}
