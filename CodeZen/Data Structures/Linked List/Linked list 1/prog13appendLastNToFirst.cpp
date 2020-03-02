//Append the last n elements of a linked list to the front
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

int lengthOfLL(node *head)
{
    if (head == NULL)
        return 0;
    else
        return 1 + lengthOfLL(head->next);
}
node *append_LinkedList(node *head, int n)
{
    int length = lengthOfLL(head);

    int breakPoint = length - n - 1;
    node *part1end = head;

    while (breakPoint--)
        part1end = part1end->next;

    node *part2start = part1end->next;
    node *part2end = part2start;

    while (part2end->next != NULL)
        part2end = part2end->next;

    part2end->next = head;
    part1end->next = NULL;

    return part2start;
}

int main()
{
    node *head = takeinput();
    int n;
    cin >> n;
    head = append_LinkedList(head, n);
    print(head);
    return 0;
}
