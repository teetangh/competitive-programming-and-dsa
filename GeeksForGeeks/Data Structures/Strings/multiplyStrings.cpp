// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2)
    {
        bool productPostive = false;

        int n1 = s1.size();
        int n2 = s2.size();

        if ((s1[0] == '-' && s2[0] == '-') || (s1[0] != '-' && s2[0] != '-'))
            productPostive = true;

        string s3(n1 + n2 + 1, '0');

        for (int j = n2 - 1; j >= 0; j--)
        {
            if (s2[j] == '-')
                continue;
            for (int i = n1 - 1; i >= 0; i--)
            {
                if (s1[i] == '-')
                    continue;

                int x = s1[i] - '0';
                int y = s2[j] - '0';

                int product = (x * y);
                int carry = (s3[i + j + 1] - '0') * 10 + (s3[i + j + 2] - '0');
                int result = product + carry;

                s3[i + j + 2] = result % 10 + '0';
                s3[i + j + 1] = result / 10 + '0';
            }
        }

        if (productPostive)
        {
            while (!s3.empty() && (s3[0]) == '0')
            {
                if (s3.size() == 1 && s3[0] == '0')
                    break;
                s3.erase(s3.begin());
            }
        }
        else
        {
            s3[0] = '-';
            while (!s3.empty() && (s3[1]) == '0')
            {
                if (s3.size() == 2 && s3[1] == '0')
                {
                    s3.erase(s3.begin());
                    break;
                }
                s3.erase(s3.begin() + 1);
            }
        }

        return s3;
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
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;
    }

} // } Driver Code Ends