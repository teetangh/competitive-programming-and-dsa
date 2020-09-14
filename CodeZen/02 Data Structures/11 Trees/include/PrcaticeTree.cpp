#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class TreeNode
{
public:
	T data;
	vector<TreeNode *> children;

	TreeNode(T data)
	{
		this->data = data;
	}
	~TreeNode()
	{
		for (int i = 0; i < children.size(); ++i)
		{
			delete (children[i]);
		}
	}
};

TreeNode<int> *takeInputLevelwise()
{
	int rootData;
	cin >> rootData;
	if (rootData == -1)
		return NULL;
	TreeNode<int> *root = new TreeNode<int>(rootData);
	queue<TreeNode<int> *> pendingNodes;
	pendingNodes.push(root);

	while (!pendingNodes.empty())
	{
		TreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();

		int numChild;
		cin >> numChild;

		for (int i = 0; i < numChild; ++i)
		{
			int childData;
			cin >> childData;
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
	cin >> rootData;
	if (rootData == -1)
		return NULL;
	TreeNode<int> *root = new TreeNode<int>(rootData);

	int numChild;
	cin >> numChild;

	for (int i = 0; i < numChild; ++i)
	{
		TreeNode<int> *child = takeInput();
		root->children.push_back(child);
	}

	return root;
}

void printTreeLevelwise(TreeNode<int> *root)
{
	queue<TreeNode<int> *> pendingNodes;
	pendingNodes.push(root);

	while (pendingNodes.size() != 0)
	{
		TreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();

		cout << front->data << " : " << endl;

		for (int i = 0; i < front->children.size(); ++i)
		{
			if (i != front->children.size() - 1)
				cout << front->children[i]->data << "," << endl;
			else
				cout << front->children[i]->data << " " << endl;

			pendingNodes.push(front->children[i]);
		}
		cout << endl;
	}
}

void printTree(TreeNode<int> *root)
{
	if (root == NULL)
		return;
	cout << root->data << " : ";

	for (int i = 0; i < root->children.size(); ++i)
		cout << root->children[i]->data << " ";

	for (int i = 0; i < root->children.size(); ++i)
		printTree(root->children[i]);
}