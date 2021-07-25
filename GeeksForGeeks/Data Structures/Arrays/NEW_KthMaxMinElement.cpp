// { Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {
        //code here
        // int hashMap[10001];
        int *hashMap = (int *)calloc(10001, sizeof(int));

        for (int i = l; i <= r; i++)
            hashMap[arr[i]]++;

        int rank = 0;
        int possibleAns = INT_MIN;
        for (int i = 1; i < 10001; i++)
        {
            if (hashMap[i] > 0)
            {
                possibleAns = i;
                rank++;
            }

            if (rank == k)
                break;
        }

        // delete hashMap;
        return (possibleAns != INT_MIN) ? possibleAns : -1;
        // return possibleAns;
    }
};

// { Driver Code Starts.

int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        int number_of_elements;
        cin >> number_of_elements;
        int a[number_of_elements];

        for (int i = 0; i < number_of_elements; i++)
            cin >> a[i];

        int k;
        cin >> k;
        Solution ob;
        cout << ob.kthSmallest(a, 0, number_of_elements - 1, k) << endl;
    }
    return 0;
} // } Driver Code Ends