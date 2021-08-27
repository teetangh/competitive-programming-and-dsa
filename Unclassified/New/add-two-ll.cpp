// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class LLNode
{
public:
    int val;
    LLNode *next;
};

LLNode *reverse(LLNode *head)
{
    LLNode *curr = head;
    LLNode *prev = NULL;
    LLNode *Next = NULL;

    while (curr != NULL)
    {
        Next = curr->next;

        curr->next = prev;

        prev = curr;
        curr = Next;
    }

    return prev;
}

LLNode *solve(LLNode *head1, LLNode *head2)
{

    auto temp1 = reverse(head1);
    auto temp2 = reverse(head2);

    LLNode *temp3Head = NULL;
    LLNode *temp3Tail = NULL;

    int carry = 0;
    while (temp1 && temp2)
    {
        LLNode *newNode = new LLNode();
        auto sum = temp1->val + temp2->val + carry;

        newNode->val = sum % 10;
        carry = sum / 10;

        if (temp3Head == NULL)
            temp3Head = temp3Tail = newNode;
        else
        {
            temp3Tail->next = newNode;
            temp3Tail = temp3Tail->next;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    while (temp1)
    {
        LLNode *newNode = new LLNode();
        auto sum = temp1->val + carry;

        newNode->val = sum % 10;
        carry = sum / 10;

        if (temp3Head == NULL)
            temp3Head = temp3Tail = newNode;
        else
        {
            temp3Tail->next = newNode;
            temp3Tail = temp3Tail->next;
        }

        temp1 = temp1->next;
    }

    while (temp2)
    {
        LLNode *newNode = new LLNode();
        auto sum = temp2->val + carry;

        newNode->val = sum % 10;
        carry = sum / 10;

        if (temp3Head == NULL)
            temp3Head = temp3Tail = newNode;
        else
        {
            temp3Tail->next = newNode;
            temp3Tail = temp3Tail->next;
        }
        temp2 = temp2->next;
    }

    LLNode *newNode = new LLNode();
    newNode->val = carry;
    temp3Tail->next = newNode;
    temp3Tail = temp3Tail->next;

    auto result = reverse(temp3Head);
    return result;
}