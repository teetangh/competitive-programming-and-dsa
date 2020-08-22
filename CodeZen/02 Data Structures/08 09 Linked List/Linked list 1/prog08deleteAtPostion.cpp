#include <iostream>
#include "../include/FINALLinkedList.hpp"
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
        Node *to_be_deleted = temp->next;
        if (to_be_deleted != NULL)
        {
            temp->next = temp->next->next;
            delete to_be_deleted;
        }
        return head;
    }
}

int main()
{
    Node *head = takeInput_Better();
    int pos;
    cin >> pos;
    head = deleteNode(head, pos);
    print(head);
    return 0;
}
