//merge sort recursive
#include <iostream>
#include "../include/CNLinkedList.hpp"
// #include "../include/FINALLinkedList.hpp"

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
    if (head == NULL || head->next == NULL)
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
int main()
{
    node *head1 = takeinput();
    node *head2 = takeinput();
    node *head3 = mergeTwoLLs(head1, head2);
    print(head3);
    return 0;
}
