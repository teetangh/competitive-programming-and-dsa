// arr - input array
// n - size of array
// val - element to be searched

int linearSearch(int arr[], int n, int val)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val)
            return (i);
    }

    return -1;
}