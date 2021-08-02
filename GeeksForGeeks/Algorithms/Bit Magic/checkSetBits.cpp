// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int isBitSet(int N)
    {
        // code here

        while (N > 0)
        {
            if (N & 1 != 0)
            {
                N = N >> 1;
                continue;
            }
            return false;
        }

        return true;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isBitSet(N) << endl;
    }
    return 0;
} // } Driver Code Ends