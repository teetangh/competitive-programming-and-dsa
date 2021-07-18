// { Driver Code Starts
#include <iostream>
using namespace std;

/* Link list Node */
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

Node *sortedMerge(struct Node *a, struct Node *b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int data;
        cin >> data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin >> data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin >> data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for (int i = 1; i < m; i++)
        {
            cin >> data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to merge two sorted linked list.
Node *sortedMerge(Node *head1, Node *head2)
{
    struct Node *mainList;
    struct Node *otherList;
    struct Node *answerHead;

    if (head1->data <= head2->data)
    {
        mainList = head1;
        otherList = head2;
        answerHead = head1;
    }
    else
    {
        mainList = head2;
        otherList = head1;
        answerHead = head2;
    }

    struct Node *tempNext = NULL;

    while (mainList != NULL && otherList != NULL)
    {
        if (mainList->data <= otherList->data)
        {
            if (mainList->next == NULL)
            {
                mainList->next = otherList;
                break;
            }
            if (mainList->next->data > otherList->data)
            {
                tempNext = mainList->next;
                mainList->next = otherList;
                mainList = tempNext;
            }
            else
                mainList = mainList->next;
        }
        else
        {
            if (otherList->next == NULL)
            {
                otherList->next = mainList;
                break;
            }
            if (otherList->next->data >= mainList->data)
            {
                tempNext = otherList->next;
                otherList->next = mainList;
                otherList = tempNext;
            }
            else
                otherList = otherList->next;
        }
    }

    return answerHead;
}

// // Sample IO
// 4

// 4 3
// 5 10 15 40
// 2 3 20

// 2 2
// 1 1
// 2 4

// 3 14
// 41 64 73
// 11 16 23 29 37 41 44 47 53 57 59 62 68 78

// 2 8
// 61 90
// 2 4 27 36 42 53 91 95

// OUTPUT
// 2 3 5 10 15 20 40
// 1 1 2 4
// 11 16 23 29 37 41 41 44 47 53 57 59 62 64 68 73 78
// 2 4 27 36 42 53 61 90 91 95
