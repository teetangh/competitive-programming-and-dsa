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
        int low = 0;
        int mid = 0;
        int high = n - 1;

        while (mid <= high)
        {

            // if (arr[low] == 2 && arr[high] == 0 ) swap(arr[low] , arr[high]);
            // else if (arr[mid] == 0 && (arr[high] == 1 || arr[high] == 2 ) ) swap(arr[low] , arr[mid]);
            // else if (arr[mid] == 2 && (arr[high] == 0 || arr[high] == 1 ) ) swap(arr[mid] , arr[high]);

            // if(arr[low] == 0 ) low++;
            // // if(arr[mid] == 1) mid++;
            // if(arr[high] == 2) high--;

            if (arr[mid] == 0)
            {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 2)
            {
                swap(arr[mid], arr[high]);
                high--;
            }
            else
                mid++;
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