#include <iostream>
#include "FINALLinkedList.hpp"

Node *deleteNodeRec(Node *head, int i)
{
    if (head == NULL)
        return NULL;
    else
    {
        if (i == 0)
        {
            Node *del = head;
            head = head->next;
            delete del;
            return head;
        }
        else
        {
            head->next = deleteNodeRec(head->next, i - 1);
            return head;
        }
    }
}
int main()
{
    Node *head = takeInput_Better();
    int pos;
    cin >> pos;
    head = deleteNodeRec(head, pos);
    print(head);
    return 0;
}
