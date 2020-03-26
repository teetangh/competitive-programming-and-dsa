#include <iostream>
using namespace std;
#include "../include/FINALLinkedList.hpp"

Node *insertNodeRec(Node *head, int i, int data)
{
    if (head == NULL)
    {
        if (i == 0)
        {
            Node *temp = new Node(data);
            return temp;
        }
        else
            return head;
    }
    else
    {
        if (i == 0)
        {
            Node *temp = new Node(data);
            temp->next = head;
            return temp;
        }
        else
        {
            head->next = insertNodeRec(head->next, i - 1, data);
            return head;
        }
    }
}

int main()
{
    Node *head = takeInput_Better();
    int pos, data;
    cin >> pos >> data;
    head = insertNodeRec(head, pos, data);
    print(head);
    return 0;
}