#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n;

    printf("\nEnter size of array\n");
    scanf("%d", &n);
    int *arr = (int *)calloc(n, sizeof(int));

    printf("\nPlease enter array elements\n");
    for (int i = 0; i < n; i++)
        scanf(" %d", &arr[i]);

    // Bubble Sorting
    for (int i = 0; i < n; i++)
    {
        bool isSorted = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                isSorted = false;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (isSorted)
            break;
    }
    printf("\nThe array elements after bubble sorting are\n");
    for (int i = 0; i < n; i++)
        printf(" %d", arr[i]);
}