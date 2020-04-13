#include <iostream>
#include <vector>
#include <queue>
#include "..\include\TreeNode.hpp"
using namespace std;

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root Data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << " Enter num of children of " << front->data << endl;
        int numChild;
        cin >> numChild;

        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childData;

            // Statically allocated and would be deallocated after each iteration
            // TreeNode<int> child(childData);

            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout << " Enter number of children of " << rootData << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int> *root)
{
    // Most of Tree problems use recursion

    //EDGE CASE NOT BASE CASE
    if (root == NULL)
        return;

    cout << root->data << " : ";

    // children.size() is Working as a base Case

    for (int i = 0; i < root->children.size(); i++)
        cout << root->children[i]->data << ",";
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
        printTree(root->children[i]);
}

int main()
{
    //STATICALLY INPUT
    // TreeNode<int> *root = new TreeNode<int>(1);
    // TreeNode<int> *node1 = new TreeNode<int>(2);
    // TreeNode<int> *node2 = new TreeNode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);

    //DYNAMICALLY INPUT
    // TreeNode<int> *root = takeInput();
    // printTree(root);

    //DYNAMICALLY INPUT
    TreeNode<int> *root = takeInputLevelWise();
    printTree(root);

    // TODO Delete Tree
}