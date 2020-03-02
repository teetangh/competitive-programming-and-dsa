//Eliminate duplicates from a sorted linked list
#include <iostream>
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
using namespace std;
// #include "solution.h"
node *takeinput()
{
    int data;
    cin >> data;
    node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node *eliminate_duplicate(node *head)
{
    if (head == NULL)
        return head;
    node *curr = head;
    node *dup;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            dup = curr->next;
            curr->next = curr->next->next;
            delete dup;
        }
        else
            curr = curr->next;
    }
    return head;
}
int main()
{
    node *head = takeinput();
    head = eliminate_duplicate(head);
    print(head);
    return 0;
}
