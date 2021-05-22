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

    // Selection Sorting
    int i, j, temp, minIndex;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        if (i != minIndex)
        {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    printf("\nThe array elements after selection sorting are\n");
    for (int i = 0; i < n; i++)
        printf(" %d", arr[i]);
}