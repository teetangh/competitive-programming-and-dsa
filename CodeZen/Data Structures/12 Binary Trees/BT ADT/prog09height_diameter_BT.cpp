#include <iostream>
// #include <bits/stdc++.h>
#include "..\include\FINALBinaryTree.hpp"
using namespace std;

int height(BinaryTreeNode<int> *root)
{
    // Base Case
    if (root == NULL)
        return 0;
    // Recursive Call
    return 1 + max(height(root->left), height(root->right));
}

int diamter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int option1 = height(root->left) + height(root->right);
    int option2 = diamter(root->left);
    int option3 = diamter(root->right);
    return max(option1, max(option2, option3));
}
// Better approach would be to return both simultaneously
pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));

    pair<int, int> p;
    p.first = height;
    p.second = diameter;

    return p;
}
// 1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    pair<int, int> p = heightDiameter(root);
    cout << "Height: " << p.first << endl;
    cout << "Diameter: " << p.second << endl;
    delete root;
    return 0;
}