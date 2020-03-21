#include <iostream>
// #include "CNLinkedList.hpp"
#include "FINALLinkedList.hpp"

Node *mergeTwoLLs(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *temp3 = NULL;
    Node *temp3head;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            Node *newNode = new Node(temp1->data);
            if (temp3 == NULL)
            {
                temp3 = newNode;
                temp3head = temp3;
            }
            else
            {
                temp3->next = newNode;
                temp3 = temp3->next;
            }
            temp1 = temp1->next;
        }
        else
        {
            Node *newNode = new Node(temp2->data);
            if (temp3 == NULL)
            {
                temp3 = newNode;
                temp3head = temp3;
            }
            else
            {
                temp3->next = newNode;
                temp3 = temp3->next;
            }
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL)
    {
        Node *newNode = new Node(temp1->data);
        if (temp3 == NULL)
        {
            temp3 = newNode;
            temp3head = temp3;
        }
        else
        {
            temp3->next = newNode;
            temp3 = temp3->next;
        }

        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        Node *newNode = new Node(temp2->data);
        if (temp3 == NULL)
        {
            temp3 = newNode;
            temp3head = temp3;
        }
        else
        {
            temp3->next = newNode;
            temp3 = temp3->next;
        }
        temp2 = temp2->next;
    }
    return temp3head;
}
int main()
{
    Node *head1 = takeInput_Better();
    Node *head2 = takeInput_Better();
    Node *head3 = mergeTwoLLs(head1, head2);
    print(head3);
    return 0;
}