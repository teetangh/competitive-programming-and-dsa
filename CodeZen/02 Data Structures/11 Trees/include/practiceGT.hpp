#include <iostream>
#include <vector>
#include <queue>
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
		for (int i = 0; i < children.size(); ++i)
		{
			delete children[i];
		}
	}
};

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
	}
}

TreeNode<int> *takeInputLevelWise()
{
	int rootData;
	cout << "Enter Root Data" << endl;
	cin >> rootData;

	TreeNode<int> *root = new TreeNode<int>(rootData);
	queue<TreeNode<int> *> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0)
	{
		TreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();

		int numChild;
		cout << "Enter number of children of " << front->data << endl;
		cin >> numChild;

		int childData;
		for (int i = 0; i < numChild; ++i)
		{
			int childData;
			cout << "Enter data of the ith child of " << front->data << endl;
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
	cout << "Enter Data" << endl;
	cin >> rootData;

	TreeNode<int> *root = new TreeNode<int>(rootData);
	cout << "Enter number of children of " << rootData << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		TreeNode<int> *child = takeInput();
		root->children.push_back(child);
	}
	return root;
}
