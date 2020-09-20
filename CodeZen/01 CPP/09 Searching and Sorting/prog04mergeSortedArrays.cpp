#include <iostream>
// #include "Solution.h"
using namespace std;

void merge(int arr1[], int size1, int arr2[], int size2, int ans[])
{
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;
    while (i < size1 && j < size2)
    {
        if (arr1[i] <= arr2[j])
            ans[k++] = arr1[i++];
        if (arr1[i] > arr2[j])
            ans[k++] = arr2[j++];
    }
    while (i < size1)
        ans[k++] = arr1[i++];

    while (j < size2)
        ans[k++] = arr2[j++];
}

int main()
{
    int size1;
    cin >> size1;
    int *arr1 = new int[size1];
    for (int i = 0; i < size1; i++)
    {
        cin >> arr1[i];
    }
    int size2;
    cin >> size2;
    int *arr2 = new int[size2];
    for (int i = 0; i < size2; i++)
    {
        cin >> arr2[i];
    }

    int *ans = new int[size1 + size2];

    merge(arr1, size1, arr2, size2, ans);

    for (int i = 0; i < size1 + size2; i++)
    {
        cout << ans[i] << " ";
    }
    delete arr1;
    delete arr2;
    delete ans;
}
// Sample Input 1 :
// 1
// 5
// 1 3 4 7 11
// 4
// 2 4 6 13
// Sample Output 1 :
// 1 2 3 4 4 6 7 11 13 
// Sample Input 2 :
// 2
// 3
// 10 100 500
// 7
// 4 7 9 25 30 300 450
// 4
// 7 45 89 90
// 0
// Sample Output 2 :
// 4 7 9 10 25 30 100 300 450 500
// 7 45 89 90