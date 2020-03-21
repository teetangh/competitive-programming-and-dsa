#include <iostream>
using namespace std;
#include "Node.cpp"

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    while (data != -1)
    {
        // Static allocation leads to deallocation at every iteration
        // Node n(data);
        Node *newNode = new Node(data);

        if (head == NULL)
            head = newNode;

        else
        {
            // head->next = newNode;
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
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
}

int main()
{
    Node *head = takeInput();
    print(head);
}