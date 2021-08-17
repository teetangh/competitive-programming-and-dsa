// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{

    // int directions = 4;
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    bool isValid(vector<vector<int>> &hospital, int i, int j)
    {
        if (i < 0 || i > hospital.size() - 1)
            return false;

        if (j < 0 || j > hospital[0].size() - 1)
            return false;

        if (hospital[i][j] == 0)
            return false;

        return true;
    }

    int dfs(vector<vector<int>> &hospital, int i, int j, int timer)
    {

        hospital[i][j] = 2;

        int maxTimer = timer + 1;
        int temp = INT_MIN;
        for (int k = 0; k < 4; k++)
        {
            int newX = i + dx[k];
            int newY = j + dy[k];
            if (isValid(hospital, newX, newY) && hospital[newX][newY] == 1)
            {
                temp = dfs(hospital, newX, newY, timer);
                if (temp > maxTimer)
                    maxTimer = timer;
            }
        }

        return maxTimer;
    }

public:
    int helpaterp(vector<vector<int>> &hospital)
    {
        //code here
        int globalTimer = INT_MIN;
        int temp = INT_MIN;
        for (int i = 0; i < hospital.size(); i++)
        {
            int timer = 1;
            for (int j = 0; j < hospital[i].size(); j++)
            {
                if (isValid(hospital, i, j) && hospital[i][j] == 2)
                {
                    temp = dfs(hospital, i, j, timer);
                    if (temp > globalTimer)
                        globalTimer = temp;
                }
            }
        }

        for (int i = 0; i < hospital.size(); i++)
        {
            for (int j = 0; j < hospital[i].size(); j++)
                cout << hospital[i][j] << " ";
            cout << endl;
        }

        for (int i = 0; i < hospital.size(); i++)
            for (int j = 0; j < hospital[i].size(); j++)
                if (hospital[i][j] == 1)
                    return -1;

        return globalTimer;
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
        int R;
        int C;

        cin >> R >> C;
        vector<vector<int>> hospital;
        int i, j;
        for (i = 0; i < R; i++)
        {
            vector<int> temp;
            for (j = 0; j < C; j++)
            {
                int k;
                cin >> k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
        }

        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
} // } Driver Code Ends