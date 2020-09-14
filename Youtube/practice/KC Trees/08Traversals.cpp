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

void preorder(Node *root)
{
    if (!root)
        return;

    cout << root->data << "\t";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if (!root)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << "\t";
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
    cout << endl;
    preorder(n10);
    cout << endl;
    postorder(n10);
}
// 40	20	50	10	30	70	
// 10	20	40	50	30	70	
// 40	50	20	70	30	10	