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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    Node *n10 = new Node(10);
    Node *n20 = new Node(20);
    Node *n30 = new Node(30);
    Node *n40 = new Node(40);
    Node *n50 = new Node(50);
    Node *n70 = new Node(70);

    n10->left = n20;
    n10->right = n30;

    n20->left = n40;
    n20->right = n50;

    n30->right = n70;

    inorder(n10);
    insert_level_order(n10, 60);

    cout << endl;
    inorder(n10);
}
