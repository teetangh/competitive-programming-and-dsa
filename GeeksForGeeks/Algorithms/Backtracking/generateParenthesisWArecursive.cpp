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
        if (n == 1)
            return {"()"};
        // else if (n == 2)
        //     return {"(())", "()()"};

        vector<string> smallAnswer = AllParenthesis(n - 1);
        unordered_set<string> us;

        for (string s : smallAnswer)
        {
            string temp = s + "()";
            us.insert(temp);

            temp = "()" + s;
            us.insert(temp);

            temp = '(' + s + ')';
            us.insert(temp);
        }

        vector<string> result;
        for (auto ele : us)
            result.emplace_back(ele);

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