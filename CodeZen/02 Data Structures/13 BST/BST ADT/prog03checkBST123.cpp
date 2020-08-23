#include <iostream>
// #include <bits/stdc++.h>
#include "../include/FINALBinaryTree.hpp"
#include <climits>
using namespace std;
////////////////////////////////////////////////////////////////////////////////IMPLEMENTATION1///////////////////////////////////////////////////////////////////////////////////////////
int maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return INT_MIN;
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
int minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return INT_MAX;
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root) // O(nh)
{
    if (root == NULL)
        return true;

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
    return output;
}

////////////////////////////////////////////////////////////////////////////////IMPLEMENTATION2///////////////////////////////////////////////////////////////////////////////////////////
class IsBSTReturn
{
    // A Triplet class to avoid pair class confusion
public:
    bool isBST;
    int minimum;
    int maximum;
};

IsBSTReturn isBST2(BinaryTreeNode<int> *root) //O(n)
{
    if (root == NULL)
    {
        IsBSTReturn output;
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }

    IsBSTReturn leftOutptut = isBST2(root->left);
    IsBSTReturn rightOutptut = isBST2(root->right);

    int minimum = min(root->data, min(leftOutptut.minimum, rightOutptut.minimum));
    int maximum = max(root->data, max(leftOutptut.maximum, rightOutptut.maximum));
    bool isBSTFinal = (root->data > leftOutptut.maximum) && (root->data <= rightOutptut.minimum) && leftOutptut.isBST && rightOutptut.isBST;

    IsBSTReturn output;
    output.minimum = minimum;
    output.maximum = maximum;
    output.isBST = isBSTFinal;

    return output;
}

////////////////////////////////////////////////////////////////////////////////IMPLEMENTATION3///////////////////////////////////////////////////////////////////////////////////////////
// Bottom-up Approach

bool isBST3(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
        return true;

    if (root->data < min || root->data > max)
        return false;

    bool isLeftOk = isBST3(root->left, min, root->data - 1);
    bool isRightOk = isBST3(root->right, root->data, max);
    return isLeftOk && isRightOk;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 False
// 4 3 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1 True
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    if (isBST(root))cout << "the given BT is a BST1" << endl;else cout << "the given BT is NOT a BST1" << endl;
    if (isBST2(root).isBST)cout << "the given BT is a BST2" << endl;else cout << "the given BT is NOT a BST2" << endl;
    if (isBST3(root))cout << "the given BT is a BST3" << endl;else cout << "the given BT is NOT a BST3" << endl;
}

////////////////////////////////////////////////////////////////////////////////SAMPLE_IO///////////////////////////////////////////////////////////////////////////////////////////
// // Sample IO 1
// Enter Data
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// Enter Left Child of 1
// Enter Right Child of 1
// Enter Left Child of 2
// Enter Right Child of 2
// Enter Left Child of 3
// Enter Right Child of 3
// Enter Left Child of 4
// Enter Right Child of 4
// Enter Left Child of 5
// Enter Right Child of 5
// Enter Left Child of 6
// Enter Right Child of 6
// Enter Left Child of 7
// Enter Right Child of 7
// Enter Left Child of 8
// Enter Right Child of 8
// Enter Left Child of 9
// Enter Right Child of 9
// the given BT is NOT a BST1
// the given BT is NOT a BST2
// the given BT is NOT a BST3

// // Sample IO 2 
// Enter Data
// 4 3 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
// Enter Left Child of 4
// Enter Right Child of 4
// Enter Left Child of 3
// Enter Right Child of 3
// Enter Left Child of 6
// Enter Right Child of 6
// Enter Left Child of 1
// Enter Right Child of 1
// Enter Left Child of 3
// Enter Right Child of 3
// Enter Left Child of 5
// Enter Right Child of 5
// Enter Left Child of 7
// Enter Right Child of 7
// the given BT is a BST1
// the given BT is a BST2
// the given BT is a BST3