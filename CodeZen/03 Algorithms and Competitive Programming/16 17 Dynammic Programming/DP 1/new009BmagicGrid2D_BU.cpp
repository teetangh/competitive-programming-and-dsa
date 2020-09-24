#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printDP(vector<vector<int>> dp)
{
    cout << " =======================================" << endl;
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
    cout << " =======================================" << endl;
}
int minimum_health(vector<vector<int>> maze, int rows, int columns)
{
    vector<vector<int>> dp;
    dp.resize(rows + 1, vector<int>(columns + 1, 0));

    dp[rows][columns] = 1;
    // dp[rows][columns - 1] = 1;
    // dp[rows - 1][columns] = 1;

    for (int i = rows - 1; i >= 1; i--)
    {
        dp[i][columns] = dp[i + 1][columns] - maze[i][columns];
        if (dp[i][columns] < 1)
            dp[i][columns] = 1;
    }
    for (int j = columns - 1; j >= 1; j--)
    {   
        dp[rows][j] = dp[rows][j + 1] - maze[rows][j];
        if (dp[rows][j] < 1)
            dp[rows][j] = 1;
    }

    for (int i = rows - 1; i >= 1; i--)
    {
        for (int j = columns - 1; j >= 1; j--)
        {
            dp[i][j] = maze[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
            if (dp[i][j] < 1)
                dp[i][j] = 1;
        }
    }

    printDP(dp);

    int answer = dp[1][1];
    dp.clear();
    return answer;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        int rows, columns;
        cin >> rows >> columns;

        vector<vector<int>> maze;
        maze.resize(rows + 1, vector<int>(columns + 1, 0));

        for (int i = 1; i <= rows; i++)
            for (int j = 1; j <= columns; j++)
                cin >> maze[i][j];

        cout << minimum_health(maze, rows, columns) << endl;
        maze.clear();
    }

    return 0;
}
// // Sample IO
// 6
// 2 3
// 0 1 -3
// 1 -2 0
// 2 2
// 0 1
// 2 0
// 3 4
// 0 -2 -3 1
// -1 4 0 -2
// 1 -2 -3 0
// 5 8
// 0 -86 -8 -29 -71 -18 -25 92 
// 93 -46 -82 -89 -74 -96 -2 -84 
// -93 -81 -61 -97 83 -52 -58 -54 
// -7 83 -96 2 -19 -96 65 -77 
// -100 65 37 -54 3 -23 -52 0 
// 7 7
// 0 -16 37 92 -98 16 -90 
// -96 -53 14 -7 -98 44 -92 
// -61 -43 93 -84 -98 -75 -59 
// 29 -16 -8 -66 -65 81 -75 
// -99 -88 46 12 13 -12 -94 
// 99 79 34 -3 -57 2 -79 
// -40 -52 69 -80 -9 -33 0 
// 6 5
// 0 -80 -53 85 -13 
// 45 35 -73 -73 89 
// -80 -11 61 -63 -15 
// -90 -97 -68 -79 -10 
// -43 -92 92 -24 78 
// 59 -5 10 -94 0 


//  =======================================
// 0	0	0	0	
// 0	2	4	4	
// 0	2	3	1	
//  =======================================
// 2
//  =======================================
// 0	0	0	
// 0	1	1	
// 0	1	1	
//  =======================================
// 1
//  =======================================
// 0	0	0	0	0	
// 0	1	1	1	2	
// 0	4	7	3	3	
// 0	5	6	4	1	
//  =======================================
// 1
//  =======================================
// 0	0	0	0	0	0	0	0	0	
// 0	1	1	1	1	1	1	33	124	
// 0	94	1	1	1	1	1	58	216	
// 0	1	1	1	1	84	1	60	132	
// 0	77	84	1	3	1	1	118	78	
// 0	125	25	90	127	73	76	53	1	
//  =======================================
// 1
//  =======================================
// 0	0	0	0	0	0	0	0	
// 0	1	1	52	93	1	90	490	
// 0	1	1	15	1	1	74	400	
// 0	1	1	94	1	1	30	308	
// 0	30	1	1	1	1	105	249	
// 0	1	1	59	13	14	24	174	
// 0	213	114	35	1	1	36	80	
// 0	146	106	54	123	43	34	1	
//  =======================================
// 1
//  =======================================
// 0	0	0	0	0	0	
// 0	1	1	1	86	14	
// 0	46	36	1	1	1	
// 0	1	1	62	1	26	
// 0	1	1	1	1	11	
// 0	1	1	93	1	1	
// 0	31	90	85	95	1	
//  =======================================
// 1
