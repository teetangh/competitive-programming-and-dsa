// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/*The node structure
struct Node {
int data;
Node * right, * left;
};*/

class Solution
{
public:
    /*The function should return the root of the modified tree*/
    Node *deleteNode(Node *root, int k)
    {
        if (root == NULL)
            return NULL;
        if (root->data == k)
        {
            Node *temp = root;
            if (temp->right == NULL)
                return temp->left;
            else if (temp->left == NULL)
                return temp->right;
            else
            {
                Node *temp1 = temp->right;
                Node *temp2 = temp->left;
                while (temp1->left != NULL)
                    temp1 = temp1->left;
                temp->data = temp1->data;
                temp->right = deleteNode(temp1->right, temp1->data);
            }
            return temp;
        }
        else
        {
            root->left = deleteNode(root->left, k);
            root->right = deleteNode(root->right, k);
            return root;
        }
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    getchar();
    while (T--)
    {
        Node *root;
        Node *tmp;
        //int i;
        root = NULL;
        string s;
        getline(cin, s);

        root = buildTree(s);
        int k;
        cin >> k;
        getchar();
        Solution obj;
        Node *R = obj.deleteNode(root, k);
        inorder(R);
        cout << endl;
    }
}

// } Driver Code Ends