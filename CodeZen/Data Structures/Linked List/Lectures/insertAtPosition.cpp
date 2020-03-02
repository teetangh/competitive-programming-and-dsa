#include <iostream>
using namespace std;
#include "Node.cpp"

Node *takeInput_Better()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        // Static allocation leads to deallocation at every iteration
        // Node n(data);
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            tail->next = newNode;
            tail = tail->next;
            // OR
            // tail = newNode;
        }

        cin >> data;
    }
    return head;
}
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
