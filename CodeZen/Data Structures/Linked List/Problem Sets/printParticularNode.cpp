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
    Node *head = takeinput();
    int pos;
    cin >> pos;
    printIthNode(head, pos);
    return 0;
}
