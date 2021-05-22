#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
	T data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;

	BinaryTreeNode(T data)
	{
		this->data = data;
	}
	~BinaryTreeNode()
	{
		delete left;
		delete right;
	}
};

class BST
{
	BinaryTreeNode<int> *root;

public:
	BST()
	{
		root = NULL;
	}
	~BST()
	{
		delete root;
	}

private:
	BinaryTreeNode<int> *insertData(BinaryTreeNode<int> *root, int data)
	{
		if (root == NULL)
		{
			BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
			return newNode;
		}
		else if (data < root->left->data)
			insertData(root->left, data);
		else
			insertData(root->right, data);

		return root;
	}

public:
	void insertData(int data) { this->root = insertData(root, data); }

private:
	BinaryTreeNode<int> *deleteData(BinaryTreeNode<int> *root, int data)
	{
		if (root == NULL)
			return NULL;
		if (data < root->data)
		{
			root->right = deleteData(root->right, data);
			return root;
		}
		else if (data > root->data)
		{
			root->left = deleteData(root->left, data);
			return root;
		}
		else
		{
			if (root->left == NULL && root->right == NULL)
			{
				delete root;
				return NULL;
			}
			else if (root->left == NULL)
			{
				BinaryTreeNode<int> *temp = root->right;
				root->right = NULL;
				delete root;
				return temp;
			}
			else if (root->right == NULL)
			{
				BinaryTreeNode<int> *temp = root->left;
				root->left = NULL;
				delete root;
				return temp;
			}

			else
			{
				BinaryTreeNode<int> *minNode = root->right;
				while (minNode->left != NULL)
					minNode = minNode->left;

				int rightMin = minNode->data;
				root->data = rightMin;
				root->right = deleteData(root->right, rightMin);
			}
		}
	}

public:
	void deleteData(int data) { this->root = deleteData(root, data); }

private:
	bool hasData(BinaryTreeNode<int> *root, int data)
	{
		if (root == NULL)
			return false;
		if (root->data == data)
			return true;
		if (data < root->data)
			return hasData(root->left, data);
		else
			return hasData(root->right, data);
	}

public:
	bool hasData(int data) { return hasData(root, data); }

private:
	void printTree(BinaryTreeNode<int> *root)
	{
		if (root == NULL)
			return;
		cout << root->data << " ";

		if (root->left)
			cout << root->left->data;
		if (root->right)
			cout << root->right->data;

		printTree(root->left);
		printTree(root->right);
	}

public:
	void printTree() { printTree(root); }
};