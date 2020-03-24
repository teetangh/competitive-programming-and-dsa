#include <iostream>
#include <algorithm>
// #include "solution.h"
using namespace std;

// arr - input array
// n - size of array

void sort012(int arr[], int n)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing output is handled automatically.
     */
    int i;
    int j = 0;
    int k;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            int temp = arr[j];
            arr[j] = 0;
            arr[i] = temp;
            j++;
            continue;
        }
    }
    for (int k = 0; k < n; k++)
    {
        if (arr[k] == 1)
        {
            int temp = arr[j];
            arr[j] = 1;
            arr[k] = temp;
            j++;
            continue;
        }
    }

    if (j == n)
    {
        return;
    }
}
// void sort012(int arr[], int n)  {

//     int i = 0;
//     int nz = 0;
//     int nt = n - 1;
//     int temp;

//     while(i<=nt)
//     {
//         if(i == nt - 1)
//         {
//             // std::cout<<" i "<<i<<" nz "<<nz<<" nt "<<nt<<" \n ";
//             temp = arr[nz];
//             arr[nz] = arr[i];
//             arr[i]= temp;

// //             temp = arr[nz + 1];
// //             arr[nz + 1] = arr[nt];
// //             arr[nt]= temp;

//         }
//         else if(arr[i] == 1)
//         {}
//         else if(arr[i] == 0)
//         {
//             temp = arr[nz];
//             arr[nz] = arr[i];
//             arr[i]= temp;
//             nz++;
//         }

//         else if(arr[i] == 2)
//         {
//             temp = arr[nt];
//             arr[nt] = arr[i];
//             arr[i]= temp;
//             nt--;
//         }
//         i++;

//     }

// }

// // arr - input array
// // n - size of array

// void sort012(int arr[], int n)  {
//     /* Don't write main().
//      * Don't read input, it is passed as function argument.
//      * No need to print or return the output.
//      * Taking input and printing output is handled automatically.
//      */
//     int count0 = 0;
//     int count1 = 0;
//     int count2 = 0;

//     for(int i = 0 ; i < n ; i++)
//     {
//         if(arr[i] == 0)count0++;
//         else if(arr[i] == 1)count1++;
//         else if(arr[i] == 2)count2++;
//     }

//     int i;
//     for(i = 0 ; i < count0 ; i ++)
//         arr[i] = 0;
//     for(;i<count0 + count1;i++)
//         arr[i] = 1;
//     for(;i<count0 + count1 + count2;i++)
//         arr[i] = 2;

// }

int main()
{

    int size_first;

    cin >> size_first;
    int *arr_first = new int[1 + size_first];

    for (int i = 0; i < size_first; i++)
        cin >> arr_first[i];

    sort012(arr_first, size_first);

    for (int i = 0; i < size_first; i++)
        cout << arr_first[i] << " ";
    return 0;
}
