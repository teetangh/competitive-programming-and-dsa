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
// Sample Input 1:
// 1
// 7
// 2 13 4 1 3 6 28
// 3
// Sample Output 1:
// 4
// Sample Input 2:
// 2
// 7
// 2 13 4 1 3 6 28
// 9
// 5
// 7 8 5 9 5      
// 5
// Sample Output 2:
// -1
// 2