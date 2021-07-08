// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

class Solution
{
public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
        if (n == 0)
            return 1;

        // Your code here
        sort(arr, arr + n);

        int smallestInteger = 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= 0)
                continue;

            else if (arr[i] == smallestInteger)
                smallestInteger++;
            else if (arr[i] == smallestInteger - 1)
                continue;
            else if (arr[i] != smallestInteger && arr[i] != smallestInteger - 1)
                return smallestInteger;
        }
        return arr[n - 1] + 1;
    }
};

// { Driver Code Starts.

int missingNumber(int arr[], int n);

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    //taking testcases
    int t;
    cin >> t;
    while (t--)
    {

        //input number n
        int n;
        cin >> n;
        int arr[n];

        //adding elements to the array
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        //calling missingNumber()
        cout << ob.missingNumber(arr, n) << endl;
    }
    return 0;
} // } Driver Code Ends

// // Sample IO
// Example 1:

// Input:
// N = 5
// arr[] = {1,2,3,4,5}
// Output: 6
// Explanation: Smallest positive missing
// number is 6.
// Example 2:

// Input:
// N = 5
// arr[] = {0,-10,1,3,-20}
// Output: 2
// Explanation: Smallest positive missing
// number is 2.