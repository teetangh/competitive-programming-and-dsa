//Eliminate duplicates from a sorted linked list
#include <iostream>
#include "CNLinkedList.hpp"

node *eliminate_duplicate(node *head)
{
    if (head == NULL)
        return head;
    node *curr = head;
    node *dup;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            dup = curr->next;
            curr->next = curr->next->next;
            delete dup;
        }
        else
            curr = curr->next;
    }
    return head;
}
int main()
{
    node *head = takeinput();
    head = eliminate_duplicate(head);
    print(head);
    return 0;
}
