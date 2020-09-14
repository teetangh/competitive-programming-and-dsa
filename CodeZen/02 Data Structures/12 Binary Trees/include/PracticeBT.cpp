#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
	T data;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;

	BinaryTreeNode(T data)
	{
		this->data = data;
		this->left = this->right = NULL;
	}

	~BinaryTreeNode()
	{
		delete left;
		delete right;
	}
};

BinaryTreeNode<int> *takeInputLevelwise()
{
	int rootData;
	cin >> rootData;
	if (rootData == -1)
		return NULL;

	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int> *> pendingNodes;
	pendingNodes.push(root);

	while (!pendingNodes.empty())
	{
		BinaryTreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();

		int leftChildData;
		cin >> leftChildData;
		if (leftChildData != -1)
		{
			BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
			root->left = leftChild;
			pendingNodes.push(leftChild);
		}

		int rightChildData;
		cin >> rightChildData;
		if (rightChildData != -1)
		{
			BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
			root->right = rightChild;
			pendingNodes.push(rightChild);
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

void printLevelAtNewLine(BinaryTreeNode<int> *root)
{
	queue<BinaryTreeNode<int> *> q;
	q.push(root);

	while (!q.empty())
	{
		BinaryTreeNode<int> *first = q.front();
		q.pop();

		if (first == NULL)
		{
			if (q.empty())
				break;
			cout << endl;
			q.push(NULL);
			continue;
		}
		cout << first->data << " ";
		if (first->left)
			q.push(first->left);
		if (first->right)
			q.push(first->right);
	}
}

void printTree(BinaryTreeNode<int> *root)
{
	if (root == NULL)
		return;

	cout << root->data << " : ";

	if (root->left)
		cout << 'L' << root->left->data;
	if (root->right)
		cout << 'R' << root->right->data;

	cout << endl;
	printTree(root->left);
	printTree(root->left);
}