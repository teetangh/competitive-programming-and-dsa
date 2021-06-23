// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int m, int b[], int n)
    {
        int hashMap[10001];

        int *unionArray = (int *)calloc(m + n, sizeof(int));

        for (int i = 0; i < m; i++)
            unionArray[i] = a[i];

        for (int i = 0; i < n; i++)
            unionArray[m + i] = b[i];

        sort(unionArray, unionArray + m + n);

        int uniqueCount = 1;

        for (int i = 1; i < m + n; i++)
        {
            if (unionArray[i] != unionArray[i - 1])
                uniqueCount++;
        }

        return uniqueCount;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, m;
        cin >> n >> m;
        int a[n], b[m];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];
        Solution ob;
        cout << ob.doUnion(a, n, b, m) << endl;
    }

    return 0;
} // } Driver Code Ends