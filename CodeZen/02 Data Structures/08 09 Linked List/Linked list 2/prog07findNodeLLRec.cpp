#include <iostream>
using namespace std;
#include "../include/FINALLinkedList.hpp"

int indexOfNRecursive(Node *head, int n)
{
    if (head == NULL || (head->data != n && head->next == NULL))
        return -1;
    else
    {
        if (head->data == n)
            return 0;
        else
        {
            int smallAns = indexOfNRecursive(head->next, n);
            if (smallAns == -1)
                return -1;
            else
                return 1 + smallAns;
        }
    }
}

int main()
{
    Node *head = takeInput();
    int n;
    cin >> n;
    cout << indexOfNRecursive(head, n);
}
