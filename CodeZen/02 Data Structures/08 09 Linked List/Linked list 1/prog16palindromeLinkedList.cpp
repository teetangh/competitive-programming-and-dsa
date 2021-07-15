//Check if a linked list is a palindrome
#include <iostream>
#include "../include/CNLinkedList.hpp"

// node *returnReverseLinkedList(node *head)
// {
//     // Will Lose original Linked List
//     if (head == NULL)
//         return NULL;
//     else if (head != NULL && head->next == NULL)
//         return head;

//     node *prev = NULL;
//     node *curr = head;
//     node *tempNext = head->next;

//     while (tempNext != NULL)
//     {
//         curr->next = prev;
//         prev = curr;
//         curr = tempNext;
//         tempNext = tempNext->next;
//     }

//     curr->next = prev;
//     return curr;
// }
// node *createReversedLinkedList(node *head)
// {
//     if (head == NULL)
//         return NULL;
//     else if (head != NULL && head->next == NULL)
//         return head;
//     else
//     {
//         node *temp = head;

//         node *newHead = NULL;
//         node *newTail = NULL;

//         while (temp != NULL)
//         {
//             node *newNode = new node(temp->data);
//             if (newHead == NULL)
//             {
//                 newHead = newNode;
//                 newTail = newNode;
//             }
//             else
//             {
//                 newTail->next = newNode;
//                 newTail = newNode;
//             }
//             temp = temp->next;
//         }
//         return returnReverseLinkedList(newHead);
//     }
// }

node *reverseLinkedListIterative(node *head)
{
    node *curr = head;
    node *prev = NULL;
    node *Next = NULL;

    while (curr != NULL)
    {
        Next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = Next;
    }

    head = prev;
    return head;
}

bool check_palindrome(node *head)
{
    node *original = head;
    // node *reverse = createReversedLinkedList(head);
    node *reverse = reverseLinkedListIterative(head);
    print(reverse);

    while (original->next != NULL && reverse->next != NULL)
    {
        if (original->data != reverse->data)
            return false;
        // cout << "debug 2" << endl;
        original = original->next;
        reverse = reverse->next;
    }

    return true;
}

int main()
{
    node *head = takeinput();
    bool ans = check_palindrome(head);
    if (ans)
        cout << "true";
    else
        cout << "false";
    return 0;
}
