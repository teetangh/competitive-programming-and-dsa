#include <iostream>
using namespace std;
#include "FINALLinkedList.hpp"

int length(Node *head)
{
    if (head == NULL)
        return 0;
    else
        return 1 + length(head->next);
}

int main()
{
    Node *head = takeInput_Better();
    int pos;
    cin >> pos;
    cout << length(head);
    return 0;
}