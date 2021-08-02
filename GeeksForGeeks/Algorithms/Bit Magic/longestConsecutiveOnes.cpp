// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

/*  Function to calculate the longest consecutive ones
*   N: given input to calculate the longest consecutive ones
*/
class Solution
{
public:
    int maxConsecutiveOnes(int N)
    {
        // code here
        int temp = N;

        int maxCount = INT_MIN;
        int count = 0;

        while (temp > 0)
        {
            int lastDigit = temp & 1;
            if (lastDigit != 0)
                count++;
            else
                count = 0;

            if (count > maxCount)
                maxCount = count;

            temp = temp >> 1;
        }

        return maxCount;
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t; //testcases
    while (t--)
    {
        int n;
        cin >> n; //input n
        Solution obj;
        //calling maxConsecutiveOnes() function
        cout << obj.maxConsecutiveOnes(n) << endl;
    }
    return 0;
} // } Driver Code Ends