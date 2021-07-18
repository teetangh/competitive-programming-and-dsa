// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{

    int lengthOfLL(struct Node *head)
    {
        if (head == NULL)
            return 0;

        return 1 + lengthOfLL(head->next);
    }

public:
    //Function to rotate a linked list.
    Node *rotate(Node *head, int k)
    {
        if (head == NULL || head->next == NULL)
            return head;

        if (k == lengthOfLL(head))
            return head;

        // Your code here
        auto part2start = head;
        auto part2end = head;
        for (int i = 1; i <= k - 1; i++)
            part2end = part2end->next;

        auto part1start = part2end->next;
        part2end->next = NULL;

        auto part1end = part1start;
        while (part1end->next != NULL)
            part1end = part1end->next;

        part1end->next = part2start;

        return part1start;
    }
};

// { Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, val, k;
        cin >> n;

        cin >> val;
        Node *head = new Node(val);
        Node *tail = head;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> val;
            tail->next = new Node(val);
            tail = tail->next;
        }

        cin >> k;

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
    }
    return 1;
}
// } Driver Code Ends