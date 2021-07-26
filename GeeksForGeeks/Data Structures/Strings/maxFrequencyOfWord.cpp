// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n)
    {
        // code here

        // String, First occurence , Frequency
        unordered_map<string, pair<int, int>> ump;

        for (int i = 0; i < n; i++)
        {
            if (ump[arr[i]].second == 0)
                ump[arr[i]].first = i;
            ump[arr[i]].second++;
        }

        int maxFrequency = INT_MIN;
        int maxFirstIndex = INT_MIN;
        string maxString = "";

        for (auto ele : ump)
        {
            if (ele.second.second >= maxFrequency)
            {
                maxString = ele.first;
                maxFrequency = ele.second.second;
            }
        }

        for (auto ele : ump)
        {
            if (ele.second.second == maxFrequency && ele.second.first > maxFirstIndex)
            {
                maxString = ele.first;
                maxFirstIndex = ele.second.first;
                maxFrequency = ele.second.second;
            }
        }
        return maxString;
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

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends