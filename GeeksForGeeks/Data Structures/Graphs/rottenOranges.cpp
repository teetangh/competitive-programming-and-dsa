// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{

public:
    //Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        // Code here
        if (grid.empty())
            return 0;
        queue<pair<int, int>> rotten;

        int total = 0;
        int count = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] != 0)
                    total++;
                if (grid[i][j] == 2)
                    rotten.push({i, j});
            }
        }

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        int timer = 0;
        while (!rotten.empty())
        {
            int k = rotten.size();
            count += k;

            while (k--)
            {
                auto front = rotten.front();
                rotten.pop();

                for (int i = 0; i < 4; i++)
                {
                    int newX = front.first + dx[i];
                    int newY = front.second + dy[i];

                    if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == 1)
                    {
                        grid[newX][newY] = 2;
                        rotten.push({newX, newY});
                    }
                }
            }

            if (!rotten.empty())
                timer++;
        }

        return (total == count) ? timer : -1;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends