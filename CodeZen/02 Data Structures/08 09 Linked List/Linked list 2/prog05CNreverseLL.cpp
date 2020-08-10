#include <iostream>
using namespace std;
#include "../include/FINALLinkedList.hpp"

class Pair
{
public:
    Node *head;
    Node *tail;
};
Node *reverseLL_3(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *smallAns = reverseLL_3(head->next);

    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return smallAns;
}

Pair reverseLL_2(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = reverseLL_2(head->next);
    smallAns.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = head;
    ans.tail = head;
    return ans;
}

Node *reverseLL_Better(Node *head)
{
    return reverseLL_2(head).head;
}

Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *smallAns = reverseLL(head->next);
    Node *temp = smallAns;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head;
    head->next = NULL;
    return smallAns;
}

int main()
{
    Node *head = takeInput_Better();
    head = reverseLL_3(head);
    print(head);
}
