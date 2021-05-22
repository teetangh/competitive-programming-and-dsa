#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int data;
    struct Node *next;
};

Node *newNode(int x)
{
    struct Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

struct Node *midlle(Node *start, Node *last)
{
    if (start == NULL)
        return NULL;

    struct Node *slow = start;
    struct Node *fast = start->next;

    while (fast != last)
    {
        fast = fast->next;
        if (fast != last)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

struct Node *binarySearch(Node *head, int value)
{
    struct Node *start = head;
    struct Node *last = NULL;

    do
    {
        Node *mid = midlle(start, last);

        if (mid == NULL)
            return NULL;

        if (mid->data == value)
            return mid;

        else if (mid->data < value)
            start = mid->next;

        else
            last = mid;

    } while (last == NULL || last != start);

    return NULL;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    Node *head = newNode(1);
    head->next = newNode(4);
    head->next->next = newNode(8);
    head->next->next->next = newNode(9);
    head->next->next->next->next = newNode(10);

    int value = 10;
    if (binarySearch(head, value) == NULL)
        printf("Value not present\n");
    else
        printf("Present");
    return 0;
}
