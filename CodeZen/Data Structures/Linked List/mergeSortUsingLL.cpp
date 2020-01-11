//merge sort recursive
#include <iostream>
using namespace std;
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

node *midpoint_linkedlist(node *head)
{
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node *mergeTwoLLs(node *head1, node *head2)
{
    node *temp1 = head1;
    node *temp2 = head2;
    node *temp3 = NULL;
    node *temp3head;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            node *newnode = new node(temp1->data);
            if (temp3 == NULL)
            {
                temp3 = newnode;
                temp3head = temp3;
            }
            else
            {
                temp3->next = newnode;
                temp3 = temp3->next;
            }
            temp1 = temp1->next;
        }
        else
        {
            node *newnode = new node(temp2->data);
            if (temp3 == NULL)
            {
                temp3 = newnode;
                temp3head = temp3;
            }
            else
            {
                temp3->next = newnode;
                temp3 = temp3->next;
            }
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL)
    {
        node *newnode = new node(temp1->data);
        if (temp3 == NULL)
        {
            temp3 = newnode;
            temp3head = temp3;
        }
        else
        {
            temp3->next = newnode;
            temp3 = temp3->next;
        }

        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        node *newnode = new node(temp2->data);
        if (temp3 == NULL)
        {
            temp3 = newnode;
            temp3head = temp3;
        }
        else
        {
            temp3->next = newnode;
            temp3 = temp3->next;
        }
        temp2 = temp2->next;
    }
    return temp3head;
}
node *mergeSort(node *head)
{
    if (head->next == NULL)
        return head;
    node *mid = midpoint_linkedlist(head);
    node *part1 = head;
    node *part2 = mid->next;
    mid->next = NULL;
    part1 = mergeSort(part1);
    part2 = mergeSort(part2);
    head = mergeTwoLLs(part1, part2);
    return head;
}

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
int main()
{
    node *head = takeinput();
    head = mergeSort(head);
    print(head);
    return 0;
}
