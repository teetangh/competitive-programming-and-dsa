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

    // Insertion Sorting
    int i, j;
    for (i = 0; i < n; i++)
    {
        int x = arr[i];
        for (j = i - 1; j >= 0 && x <= arr[j]; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = x;
    }
    printf("\nThe array elements after insertion sorting are\n");
    for (int i = 0; i < n; i++)
        printf(" %d", arr[i]);
}