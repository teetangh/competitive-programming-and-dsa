// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        multiset<int> mySet;

        for (int i = 0; i < n; i++)
            mySet.insert(arr[i]);

        int count = 0;
        vector<int> result;
        for (auto rit = mySet.rbegin(); rit != mySet.rend(); rit++)
        {
            if (count < k)
            {
                result.push_back(*rit);
                count++;
            }
            else
                break;
        }

        return result;
    }
};

// { Driver Code Starts.

int main()
{
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
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends