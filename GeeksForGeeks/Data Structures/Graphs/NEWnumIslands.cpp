// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    bool isValid(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || i > grid.size() - 1)
            return false;

        if (j < 0 || j > grid[0].size() - 1)
            return false;

        if (grid[i][j] != '1')
            return false;

        return true;
    }

    void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &visited)
    {
        visited[i][j] = true;

        int directions = 8;
        int dx[directions] = {0, -1, -1, -1, 0, 1, 1, 1};
        int dy[directions] = {-1, -1, 0, 1, 1, 1, 0, -1};

        for (int k = 0; k < directions; k++)
        {
            int newX = i + dx[k];
            int newY = j + dy[k];
            if (isValid(grid, newX, newY) && !visited[newX][newY])
                dfs(grid, newX, newY, visited);
        }
    }

public:
    //Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        int cc_count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (isValid(grid, i, j) && !visited[i][j])
                    dfs(grid, i, j, visited), cc_count++;
            }
        }

        return cc_count;
    }
};

// { Driver Code Starts.
int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
} // } Driver Code Ends