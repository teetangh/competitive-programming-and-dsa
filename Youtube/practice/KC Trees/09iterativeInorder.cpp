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

void inorder_stack(Node *root)
{
    stack<Node *> S;
    Node *curr = root;

    while (curr || !S.empty())
    {
        while (curr)
        {
            S.push(curr);
            curr = curr->left;
        }
        curr = S.top();
        S.pop();
        cout << curr->data << "\t";
        curr = curr->right;
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
    cout << endl;
    inorder_stack(n10);
}
// 40	20	50	10	30	70	
// 40	20	50	10	30	70	