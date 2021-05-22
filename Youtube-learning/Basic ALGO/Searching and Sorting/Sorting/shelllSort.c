#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter size\n");
    scanf(" %d", &n);

    int *arr = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        scanf(" %d", &arr[i]);

    int i, j, temp;
    for (int gap = n / 2; gap > 0; gap = gap / 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j = j - gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    printf(" After Shell Sorting \n");
    for (int i = 0; i < n; i++)
        printf(" %d", arr[i]);
}