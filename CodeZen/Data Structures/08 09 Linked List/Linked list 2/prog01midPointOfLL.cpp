#include <iostream>
#include "../include/CNLinkedList.hpp"

node *midpoint_linkedlist(node *head)
{
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main()
{
    node *head = takeinput();
    node *mid = midpoint_linkedlist(head);
    cout << mid->data;
    return 0;
}