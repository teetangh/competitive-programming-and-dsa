#include <iostream>
using namespace std;
#include "../include/CNLinkedList.hpp"

// ---------------------- MY GOOD ONE-------------------------
node *skipMdeleteN(node *head, int M, int N)
{
    if (M == 0)
        return NULL;
    if (head == NULL || head->next == NULL)
        return head;

    node *skip = head;
    node *del = NULL;

    while (skip != NULL)
    {
        for (int i = 1; i < M && skip != NULL; i++)
        {
            skip = skip->next;
        }

        if (skip == NULL)
            return head;
        del = skip->next;

        for (int j = 1; j <= N && del != NULL; j++)
        {
            node *temp = del;
            del = del->next;
            delete temp;
        }
        skip->next = del;
        skip = del;
    }

    return head;
}
// ---------------------- MY GOOD ONE-------------------------

// ---------------------- HARSH IMPLEMENTATION-------------------------

// node *skipMdeleteN(node *root, int m, int n)
// {
//     int cm = 0;
//     int cn = 0;
//     node *temp = root;
//     while (temp)
//     {
//         if (cm < m - 1)
//         {
//             cm++;
//             temp = temp->next;
//         }
//         else
//         {
//             if (cn == n)
//             {
//                 cm = 0;
//                 cn = 0;
//                 temp = temp->next;
//             }
//             else
//             {
//                 cn++;
//                 if (temp->next)
//                 {
//                     node *f = temp->next;
//                     temp->next = temp->next->next;
//                     free(f);
//                 }
//                 else
//                 {
//                     return root;
//                 }
//             }
//         }
//     }
//     return root;
// }
// ---------------------- HARSH IMPLEMENTATION-------------------------

// ---------------------- MY BAD ONE-------------------------

// node *skipMdeleteN(node *head, int M, int N)
// {
//     node *skip = head;
//     node *del = head;

//     while (skip)
//     {
//         for (int i = 0; i < M; i++)
//         {
//             if (!skip)
//                 return head;
//             skip = skip->next;
//         }
//         del = skip->next;

//         for (int j = 0; j < N; j++)
//         {
//             if (!del)
//                 return head;
//             del = del->next;
//         }
//         if (del != NULL)
//             skip->next = del->next;
//         // skip->next = del;
//         // skip = del;
//         else
//         {
//             skip->next = NULL;
//             break;
//         }
//     }

//     return head;
// }

// ---------------------- MY BAD ONE-------------------------
int main()
{
    node *head = takeinput();
    int m, n;
    cin >> m >> n;
    head = skipMdeleteN(head, m, n);
    print(head);
    return 0;
}