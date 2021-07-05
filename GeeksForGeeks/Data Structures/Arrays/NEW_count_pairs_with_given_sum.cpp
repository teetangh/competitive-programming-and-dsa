// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{

public:
    int getPairsCount(int arr[], int n, int k)
    {
        // code here
        int pairCount = 0;
        int *hashMap = (int *)calloc(10001, sizeof(int));

        for (int i = 0; i < n; i++)
        {
            // if(hashMap[k - arr[i]] == 0)
            // else
            pairCount = pairCount + hashMap[k - arr[i]];
            hashMap[arr[i]]++;
        }
        return pairCount;
    }
};

// { Driver Code Starts.

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }

    return 0;
} // } Driver Code Ends