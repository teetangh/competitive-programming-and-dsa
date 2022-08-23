// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define watch1(x) cout << (#x) << " is " << (x) << endl
#define watch2(x, y) cout << (#x) << " is " << (x) << " " << (#y) << " is " << (y) << endl
#define mod 1000000007
#define INF 1000000000
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, size) for (int i = 1; i <= size; i++)

// Typedefs
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

//  This is the Node class definition

class Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node(int data)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};

vector<int> topView(Node *root)
{
    // add your logic here
    if (root == NULL)
        return {};

    queue<pair<Node *, int>> pendingNodes;
    map<int, Node *> mpp;
    pendingNodes.push({root, 0});

    while (!pendingNodes.empty())
    {

        auto front = pendingNodes.front();
        pendingNodes.pop();

        if (mpp.find(front.second) == mpp.end())
        {
            mpp[front.second] = front.first;
        }

        if (front.first->left != NULL)
            pendingNodes.push({front.first->left, front.second - 1});

        if (front.first->right != NULL)
            pendingNodes.push({front.first->right, front.second + 1});
    }

    vector<int> result;
    for (auto ele : mpp)
        result.push_back(ele.second->data);
    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        Node *root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
        root->right->left = new Node(6);
        root->right->right = new Node(7);
        root->left->left->left = new Node(8);
        root->left->left->right = new Node(9);
        root->left->right->left = new Node(10);
        root->left->right->right = new Node(11);
        root->right->left->left = new Node(12);
        root->right->left->right = new Node(13);
        root->right->right->left = new Node(14);
        root->right->right->right = new Node(15);

        vector<int> result = zigzagLevelOrderTraversal(root);
        for (auto it : result)
            cout << it << " ";
        cout << endl;
    }

    return 0;
}
