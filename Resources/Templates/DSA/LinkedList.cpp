// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

// Policy Based Data Structures
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

// Defines
#define endl '\n'
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

    void printList()
    {
        ListNode *temp = this;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insertNode(int x)
    {
        ListNode *temp = this;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new ListNode(x);
    }

    void removeNode(int x)
    {
        ListNode *temp = this;
        while (temp->next != NULL)
        {
            if (temp->next->val == x)
            {
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }
    }

    ListNode *reverseList()
    {
        ListNode *prev = NULL, *curr = this, *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};