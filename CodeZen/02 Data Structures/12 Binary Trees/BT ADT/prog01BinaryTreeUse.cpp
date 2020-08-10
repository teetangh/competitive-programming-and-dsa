#include <iostream>
#include <queue>
#include "..\include\BinaryTreeNode.hpp"
using namespace std;

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter Data" << endl;
    cin >> rootData;
    if (rootData == -1)
        return NULL;

    // ROOT DATA IS NOT NULL
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    // Mainttaing a dynamic queues of node elements as the user inputs the data
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        // LEFT NODE CASE
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter Left Child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        // RIGHT NODE CASE
        cout << "Enter Right Child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }

    return root;
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Data" << endl;
    cin >> rootData;
    if (rootData == -1)
        return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << ":";

    if (root->left != NULL)
        cout << "L" << root->left->data;
    if (root->right != NULL)
        cout << "R" << root->right->data;

    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

int main(int argc, char const *argv[])
{
    // STATICALLY
    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);

    // root->left = node1;
    // root->right = node2;

    // DYANMICALLY
    BinaryTreeNode<int> *root = takeInputLevelWise();
    // BinaryTreeNode<int> *root = takeInput();
    printTree(root);
    delete root;
    return 0;
}
