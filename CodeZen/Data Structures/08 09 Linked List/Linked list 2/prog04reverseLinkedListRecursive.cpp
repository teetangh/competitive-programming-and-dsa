#include <iostream>
#include "../include/CNLinkedList.hpp"

node *reverse_linked_list_rec(node *head)
{
    //write your recursive code here
    node *p, *q;
    if (head == NULL)
        return NULL;
    p = head;
    q = p->next;
    if (q == NULL)
        return p;
    q = reverse_linked_list_rec(q);
    p->next->next = p;
    p->next = NULL;
    return q;
}

// Reverse Linked List  a. Using recursion  b. Without using recursion

int main()
{
    node *head = takeinput();
    head = reverse_linked_list_rec(head);
    print(head);
    return 0;
}
