#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

// typedefs
typedef long long ll;
typedef long long int lli;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
    ~Node() {}
};

void inorder(Node *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << "\t";
    inorder(root->right);
}

void insert_level_order(Node *root, int val)
{
    Node *nn = new Node(val);
    queue<Node *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        Node *n = Q.front();
        Q.pop();

        if (!n->left)
        {
            n->left = nn;
            return;
        }
        else if (!n->right)
        {
            n->right = nn;
            return;
        }
        else
        {
            Q.push(n->left);
            Q.push(n->right);
        }
    }
}

void remove_node(Node *root, Node *n)
{
    if (root == NULL)
        return;
    if (root == n)
    {
        delete n;
        root = NULL;
        return;
    }

    if (root->left == n)
    {
        delete n;
        root->left = NULL;
        return;
    }

    if (root->right == n)
    {
        delete n;
        root->right = NULL;
        return;
    }

    remove_node(root->left, n);
    remove_node(root->right, n);
}

Node *delete_node(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (!root->left && !root->right)
    {
        if (root->data == key)
        {
            delete root;
            root = NULL;
            return root;
        }
        return root;
    }

    queue<Node *> Q;
    Q.push(root);

    Node *key_node = NULL;
    Node *curr_node = NULL;

    while (!Q.empty())
    {
        curr_node = Q.front();
        Q.pop();

        if (curr_node->data == key)
            key_node = curr_node;
        if (curr_node->left)
            Q.push(curr_node->left);
        if (curr_node->right)
            Q.push(curr_node->right);
    }

    if (key_node)
    {
        key_node->data = curr_node->data;
        remove_node(root, curr_node);
        // curr_node = NULL;
    }

    return root;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->left = n5;
    n4->right = n6;

    inorder(n1);
    // insert_level_order(n1, 6);

    delete_node(n1, 1);
    cout << endl;
    inorder(n1);
}
// 4	6	2	1	5	3	
// 4	2	6	5	3	