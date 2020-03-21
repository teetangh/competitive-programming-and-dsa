#include <iostream>
#include "FINALLinkedList.hpp"

void printIthNode(Node *head, int i)
{

    for (int j = 0; j < i; j++)
    {
        head = head->next;
        if (head == NULL)
            return;
    }

    cout << head->data;
}

int main()
{
    Node *head = takeInput_Better();
    int pos;
    cin >> pos;
    printIthNode(head, pos);
    return 0;
}
