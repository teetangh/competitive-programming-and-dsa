#include "BinaryTreeNode.hpp"
#include <iostream>
#include <queue>

using namespace std;

BinaryTreeNode<int> *takeInputLevelWise()
{
	int rootData;
	cout << "Enter Data" << endl;
	cin >> rootData;

	if (rootData == -1)
		return NULL;
	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int> *> pendingNodes;
	pendingNodes.push(root);
	while (!pendingNodes.size())
	{
		BinaryTreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();

		int leftChildData;
		cout << "Enter left Data of " << front->left << endl;
		cin >> leftChildData;
		if (leftChildData != -1)
		{
			BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}
		int rightChildData;
		cout << "Enter right Data of " << front->right << endl;
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

void printTree(BinaryTreeNode<int> * root)
{
	if(root == NULL)
		return;
	
	cout << root->data <<":"<< endl;

	if(root->left != NULL)
		cout << "L"<<root->left << endl;
	if(root->right != NULL)
		cout << "R"<<root->right << endl;

	cout << endl;
	printTree(root->left);
	printTree(root->right);

	
}
