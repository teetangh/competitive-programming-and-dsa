#include <iostream>
#include <bits/stdc++.h>
#include "..\include\FINALBinaryTree.hpp"
using namespace std;

int numNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    return 1 + numNodes(root->left) + numNodes(root->right);
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(int argc, char const *argv[])
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    cout << "Number of Nodes: " << numNodes(root) << endl;
    delete root;
    return 0;
}
// // Sample IO
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
// 1:L2R3
// 2:L4R5
// 4:
// 5:
// 3:L6R7
// 6:L8R9
// 8:
// 9:
// 7:
// Number of Nodes: 9