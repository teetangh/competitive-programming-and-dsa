#include <iostream>
#include "../include/FINALLinkedList.hpp"
using namespace std;

Node *insertNode(Node *head, int i, int data)
{
    Node *newNode = new Node(data);

    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    else
    {
        Node *temp = head;
        for (int count = 0; temp != NULL && count < i - 1; count++)
            temp = temp->next;
        if (temp != NULL)
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }

        return head;
    }
}

int main()
{
    // Node *head = takeInput();
    // print(head);
    // printf("\n");
    Node *head2 = takeInput_Better();
    int i, data;
    cout << "Enter the postion and data to insert" << endl;
    cin >> i >> data;

    head2 = insertNode(head2, i, data);
    cout << "Final Linked List" << endl;
    print(head2);
}

// Sample IO
