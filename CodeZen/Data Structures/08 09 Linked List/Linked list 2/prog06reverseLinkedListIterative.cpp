#include <iostream>
using namespace std;
#include "../include/CNLinkedList.hpp"

node *rev_linkedlist_itr(node *head)
{
    //write your iterative code here
    if (head == NULL || head->next == NULL)
        return head;

    node *prev = NULL;
    node *curr = head;
    node *Next = curr->next;

    while (curr && Next)
    {
        curr->next = prev;

        prev = curr;
        curr = Next;
        Next = Next->next;
    }
    curr->next = prev;
    return curr;
}

int main()
{
    node *head = takeinput();
    head = rev_linkedlist_itr(head);
    print(head);
    return 0;
}
