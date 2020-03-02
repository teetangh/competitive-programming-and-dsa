#include <iostream>
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;
// #include "Solution.h"

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
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
    Node *head = takeinput();
    int pos;
    cin >> pos;
    head = deleteNode(head, pos);
    print(head);
    return 0;
}
