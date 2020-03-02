#include <iostream>
#include "FINALLinkedList.hpp"

int indexOfNIter(Node *head, int n)
{
    //Initialising some required variables
    int count = 0;
    Node *temp = head;

    //Iterating thorugh the linked list to check the presence or absence of node
    while (temp != NULL && temp->data != n)
    {
        ++count;
        temp = temp->next;
    }

    //If present returning count or else returning -1
    if (temp != NULL && temp->data == n)
        return count;
    else
        return -1;
}
int main()
{
    Node *head = takeInput_Better();
    int n;
    cin >> n;
    cout << indexOfNIter(head, n);
}
