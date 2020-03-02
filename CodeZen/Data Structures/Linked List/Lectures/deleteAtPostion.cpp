#include <iostream>
#include "FINALLinkedList.hpp"
Node *deleteNode(Node *head, int i)
{
    Node *temp = head;
    if (i == 0 && temp->next != NULL)
    {
        head = head->next;
        delete temp;
        return head;
    }
    else if (i == 0 && temp->next == NULL)
        return NULL;
    else
    {

        for (int count = 0; count < i - 1; count++)
        {
            temp = temp->next;
            if (temp == NULL)
                return head;
        }
        Node *old = temp->next;
        if (old != NULL)
        {
            temp->next = temp->next->next;
            delete old;
        }
        return head;
    }
}

int main()
{
    Node *head = takeInput();
    int pos;
    cin >> pos;
    head = deleteNode(head, pos);
    print(head);
    return 0;
}
