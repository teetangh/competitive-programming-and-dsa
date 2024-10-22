// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
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

/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node *head, int n);

/* Driver program to test above function*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    int T, i, n, l, k;

    cin >> T;

    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;

        cin >> n >> k;
        int firstdata;
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }

        cout << getNthFromLast(head, k) << endl;
    }
    return 0;
} // } Driver Code Ends

/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
int lengthOfLL(Node *temp)
{
    if (temp == NULL)
        return 0;

    return 1 + lengthOfLL(temp->next);
}
int getNthFromLast(Node *head, int k)
{
    // Your code here
    if (head == NULL)
        return -1;

    int n = lengthOfLL(head);
    int index = n - k;
    if (index < 0)
        return -1;

    auto temp = head;
    for (int i = 1 ; i <= index; i++)
    {
        temp = temp->next;
        if (temp == NULL)
            return -1;
    }

    return temp->data;
}
