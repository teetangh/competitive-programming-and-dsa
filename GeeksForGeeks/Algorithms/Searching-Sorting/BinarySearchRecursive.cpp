#include <bits/stdc++.h>
using namespace std;

int bin_search(int A[], int left, int right, int k);

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int N;
        cin >> N;
        int a[N];
        for (int i = 0; i < N; i++)
            cin >> a[i];
        int key;
        cin >> key;
        int found = bin_search(a, 0, N - 1, key);
        cout << found << endl;
    }
}
// } Driver Code Ends

/*You need to complete this function */
int bin_search(int arr[], int left, int right, int k)
{
    auto mid = (left + right) / 2;

    if (left == right && arr[mid] != k)
        return -1;

    int ans;
    if (arr[mid] == k)
        return mid;
    else if (arr[mid] > k)
        ans = bin_search(arr, left, mid - 1, k);
    else if (arr[mid] < k)
        ans = bin_search(arr, left + 1, right, k);

    if (ans == -1)
        return -1;
    else
        return ans;
}