// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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

    struct Node *reverseLinkedList(struct Node *head)
    {
        struct Node *curr = head;
        struct Node *prev = NULL;
        struct Node *Next = NULL;

        while (curr != NULL)
        {
            Next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = Next;
        }

        return prev;
    }

    struct Node *midPoint(struct Node *head)
    {
        struct Node *slow = head;
        struct Node *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        auto part1 = head;
        auto part2 = reverseLinkedList(midPoint(head));

        while (part1 != NULL && part2 != NULL)
        {
            if (part1->data != part2->data)
                return false;
            part1 = part1->next;
            part2 = part2->next;
        }

        return true;
    }
};

// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        // taking first data of LL
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.isPalindrome(head) << endl;
    }
    return 0;
}

// } Driver Code Ends