#include <iostream>
#include "../include/FINALLinkedList.hpp"

int length(Node *head)
{
    int count = 0;
    // Node * temp = head;
    while (head != NULL)
    {
        ++count;
        head = head->next;
    }
    return count;
}

int main()
{
    Node *head = takeInput_Better();
    int pos;
    cin >> pos;
    cout << length(head);
    return 0;
}
