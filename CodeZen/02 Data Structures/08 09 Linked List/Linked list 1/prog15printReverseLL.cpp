// Print a given linked list in reverse order. Tail first. You cant change any pointer in the linked list
#include <iostream>
#include "../include/CNLinkedList.hpp"

void print_linkedlist_spl(node *head)
{
    //Simply use Tail Recursion instead of Head Recursion
    if (head == NULL)
        return;
    print_linkedlist_spl(head->next);
    cout << head->data << " ";
}

int main()
{
    node *head = takeinput();
    print_linkedlist_spl(head);
    return 0;
}
