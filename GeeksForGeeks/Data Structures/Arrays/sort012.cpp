// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void sort012(int arr[], int n)
    {
        // coode here
        int i = 0;
        int j = 0;
        int k = n - 1;

        while (j <= k)
        {

            // if (arr[i] == 2 && arr[k] == 0 ) swap(arr[i] , arr[k]);
            // else if (arr[j] == 0 && (arr[k] == 1 || arr[k] == 2 ) ) swap(arr[i] , arr[j]);
            // else if (arr[j] == 2 && (arr[k] == 0 || arr[k] == 1 ) ) swap(arr[j] , arr[k]);

            // if(arr[i] == 0 ) i++;
            // // if(arr[j] == 1) j++;
            // if(arr[k] == 2) k--;

            if (arr[j] == 0)
            {
                swap(arr[i], arr[j]);
                i++;
                j++;
            }
            else if (arr[j] == 2)
            {
                swap(arr[j], arr[k]);
                k--;
            }
            else
                j++;
        }
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends