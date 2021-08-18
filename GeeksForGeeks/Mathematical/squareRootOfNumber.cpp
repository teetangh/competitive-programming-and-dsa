// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution
{
public:
    long long int floorSqrt(long long int x)
    {
        // Your code goes here

        long long int low = 1;
        long long int high = x;
        long long int mid;
        long long int temp1, temp2;

        while (low <= high)
        {
            mid = low + (high - low) / 2;
            temp1 = mid * mid;
            temp2 = (mid + 1) * (mid + 1);

            if (x == temp1 || (temp1 < x && x < temp2))
                return mid;

            else if (x < temp1)
                high = mid - 1;
            else if (x >= temp2)
                low = mid + 1;
        }

        return -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}
// } Driver Code Ends