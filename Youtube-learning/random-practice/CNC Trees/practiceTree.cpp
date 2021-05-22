#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
            delete children[i];
    }
};

void printTreeLevelwise(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << front->data << ":";

        for (int i = 0; i < front->children.size(); i++)
        {
            if (i != front->children.size() - 1)
                cout << front->children[i]->data << ",";
            else
                cout << front->children[i]->data << " ";
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}

TreeNode<int> *takeInputLevelwise()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
        return NULL;

    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        for (int i = 0; i < front->children.size(); i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            pendingNodes.push(child);
        }
    }

    return root;
}

TreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
        return NULL;

    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
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
    if (root == NULL)
        return;

    cout << root->data << " : ";

    for (int i = 0; i < root->children.size(); i++)
        cout << root->children[i]->data << " ";
    cout << " ";

    for (int i = 0; i < root->children.size(); i++)
        printTree(root->children[i]);
}