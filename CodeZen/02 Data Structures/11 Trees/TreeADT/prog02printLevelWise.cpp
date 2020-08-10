#include <iostream>
#include <bits/stdc++.h>
#include "..\include\CNTree.hpp"
using namespace std;

void printLevelWise(TreeNode<int> *root)
{
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
                cout << front->children[i]->data;

            pendingNodes.push(front->children[i]);
        }
        cout << endl;
        //for(int i = 0 ; i < front->children.size(); i++)
        //   printLevelWise(front->children[i]);
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
}