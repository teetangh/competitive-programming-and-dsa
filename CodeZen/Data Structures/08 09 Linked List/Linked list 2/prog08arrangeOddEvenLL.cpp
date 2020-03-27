#include <iostream>
using namespace std;
#include "../include/CNLinkedList.hpp"

node *arrange_LinkedList(node *head)
{
    //write your code here
    node *curr = head;

    node *oddHead = NULL;
    node *oddTail = NULL;

    node *evenHead = NULL;
    node *evenTail = NULL;

    while (curr)
    {
        int value = curr->data;
        if (value % 2 != 0) // Current Value is odd
        {
            if (oddHead == NULL)
            {
                oddHead = curr;
                oddTail = curr;
            }
            else
            {
                oddTail->next = curr;
                oddTail = oddTail->next;
            }
            //oddTail->next = NULL;
        }
        else
        {
            if (evenHead == NULL)
            {
                evenHead = curr;
                evenTail = curr;
            }
            else
            {
                evenTail->next = curr;
                evenTail = evenTail->next;
            }
            //   evenTail->next = NULL;
        }
        curr = curr->next;
    }

    if (evenTail != NULL)
        evenTail->next = NULL;
    if (oddTail != NULL)
        oddTail->next = evenHead;
    //oddTail = evenHead;
    if (oddHead != NULL)
        return oddHead;
    else
        return evenHead;
}
// node *arrange_LinkedList(node *head)
// {
//     //write your code here
//     node *prev = NULL;
//     node *curr = head;
//     node *Next = curr->next;

//     node *oddHead = NULL;
//     node *oddTail = NULL;

//     node *evenHead = NULL;
//     node *evenTail = NULL;

//     while (Next)
//     {
//         int value = curr->data;
//         if (value % 2 != 0) // Current Value is odd
//         {
//             if (oddHead == NULL)
//             {
//                 oddHead = curr;
//                 oddTail = curr;
//             }
//             else
//             {
//                 oddTail = curr;
//                 oddTail = oddTail->next;
//             }
//         }
//         else
//         {
//             if (evenHead == NULL)
//             {
//                 evenHead = curr;
//                 evenTail = curr;
//             }
//             else
//             {
//                 evenTail = curr;
//                 evenTail = evenTail->next;
//             }
//         }
//         prev = curr;
//         curr = Next;
//         Next = Next->next;
//     }
//     evenTail->next = NULL;
//     oddTail = evenHead;
//     return oddHead;
// }

int main(int argc, char const *argv[])
{
    node *head = takeinput();
    head = arrange_LinkedList(head);
    print(head);
    return 0;
}
