// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    string removeDups(string S)
    {
        // Your code goes here
        string result = "";
        unordered_set<char> us;

        for (auto ele : S)
        {
            if (us.find(ele) != us.end())
                continue;
            us.insert(ele);
            result += ele;
        }

        return result;
    }
};

// { Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
} // } Driver Code Ends