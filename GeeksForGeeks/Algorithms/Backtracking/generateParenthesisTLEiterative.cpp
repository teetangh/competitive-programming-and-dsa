// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n);

// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
public:
    vector<string> AllParenthesis(int n)
    {
        char brackets[2] = {'(', ')'};

        // Your code goes here
        int size = 2 * n;
        int subsetNum = (1 << size);

        vector<string> result;
        for (int subsetMask = 0; subsetMask < subsetNum; subsetMask++)
        {
            string currPattern;
            bool validPattern = true;
            int openCount = 0;
            int closeCount = 0;

            for (int i = 0; i < size; i++)
            {
                if ((subsetMask & (1 << i)) == 0)
                {
                    currPattern += '(';
                    openCount++;
                }
                else
                {
                    currPattern += ')';
                    closeCount++;
                }

                if (closeCount > openCount || openCount > n)
                {
                    validPattern = false;
                    break;
                }
            }

            if (validPattern)
                result.emplace_back(currPattern);
        }

        return result;
    }
};

// { Driver Code Starts.

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        vector<string> result = ob.AllParenthesis(n);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << "\n";
    }
    return 0;
}
// } Driver Code Ends