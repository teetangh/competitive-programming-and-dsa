// India and its Spirituality Submissions: 113   Accuracy: 5.3%   Max. Score: 50
// Problems
// India is well known for its spirituality and holy places, a holy place is represented by '*' (rest of the cities are represented by '.'), and all the cities which are neighbors (which shares a corner or a side) to holy places are known as spiritual cities.

// Geek wants to travel all spiritual places, but he decided to travel from one city to another city if both of them are spiritual and neighbors too.

// The task is to find the maximum number of spiritual cities geek can travel, starting from a spiritual city.

// Note: A holy place is not considered as a spiritual city

// Input:
// 1. The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases is as follows.
// 2. The first line of each test case contains two space-separated integers N and M.
// 3. Next N lines contain M characters

// Output: For each test case, print the maximum number of spiritual cities geek can travel.

// Your Task:
// This is a function problem. You only need to complete the function maxCities() that take a 2-d vector of char, m, n as parameters and returns the maximum number of spiritual cities geek can travel. The driver code automatically appends a new line.

// Constraints:
// 1. 1 <= T <= 100
// 2. 1 <= N, M <= 102

// Example:
// Input:
// 2
// 5 5
// ....*
// .....
// ..*..
// .....
// .....
// 1 2
// **

// Output:
// 10
// 0

// Explanation:
// Testcase 1: (1, 4), (2, 2), (2, 3), (2, 4), (2, 5), (3, 2), (3, 4), (4, 2), (4, 3), (4, 4) are the spiritual cities which geek will visit.
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

// Defines
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// typedefs
typedef long long ll;
typedef long long int lli;

int maxCities(vector<vector<char>> &a, int n, int m)
{
    // vector<spiritual> legend;
    vector<vector<pair<int, bool>>> spiritual_matrix;
    spiritual_matrix.resize(n, vector<pair<int, bool>>(a[0].size(), {-1, false}));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '*')
                spiritual_matrix[i][j] = {-1, false}; // legend.emplace_back(spiritual(i, j, false));

            // else if(a[i][j] == '.')
            else
            {
                bool spirituality = false;
                if (i >= 1 && j >= 1 && a[i - 1][j - 1] == '*')
                    spirituality = true;

                if (i >= 1 && a[i - 1][j] == '*')
                    spirituality = true;

                if (i >= 1 && j < m - 1 && a[i - 1][j + 1] == '*')
                    spirituality = true;

                if (j >= 1 && j < m - 1 && a[i][j + 1] == '*')
                    spirituality = true;

                if (j >= 1 && a[i][j - 1] == '*')
                    spirituality = true;

                if (i < n - 1 && j < m - 1 && a[i + 1][j + 1] == '*')
                    spirituality = true;

                if (i < n - 1 && a[i + 1][j] == '*')
                    spirituality = true;

                if (i < n - 1 && j >= 1 && a[i + 1][j - 1] == '*')
                    spirituality = true;

                if (j >= 1 && a[i][j - 1] == '*')
                    spirituality = true;

                spiritual_matrix[i][j] = {-1, spirituality}; // legend.emplace_back(spiritual(i, j, spirituality));
            }
        }
    }

    map<int, int> mp;

    int block_no = 1;

    for (int i = 1; i < spiritual_matrix.size() - 1; i++)
    {
        bool flag = false;
        for (int j = 1; j < spiritual_matrix[i].size() - 1; j++)
        {
            if (spiritual_matrix[i][j].second == true)
            {
                spiritual_matrix[i][j].first = 1;
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }

    for (int i = 1; i < spiritual_matrix.size() - 1; i++)
    {
        for (int j = 1; j < spiritual_matrix[i].size() - 1; j++)
        {
            if (spiritual_matrix[i - 1][j - 1].first != -1)
                spiritual_matrix[i][j].first = spiritual_matrix[i - 1][j - 1].first;
            if (spiritual_matrix[i - 1][j].first != -1)
                spiritual_matrix[i][j].first = spiritual_matrix[i - 1][j - 1].first;

            if (spiritual_matrix[i - 1][j + 1].first != -1)
                spiritual_matrix[i][j].first = spiritual_matrix[i - 1][j - 1].first;

            if (spiritual_matrix[i][j + 1].first != -1)
                spiritual_matrix[i][j].first = spiritual_matrix[i - 1][j - 1].first;

            if (spiritual_matrix[i][j - 1].first != -1)
                spiritual_matrix[i][j].first = spiritual_matrix[i - 1][j - 1].first;

            if (spiritual_matrix[i + 1][j + 1].first != -1)
                spiritual_matrix[i][j].first = spiritual_matrix[i - 1][j - 1].first;

            if (spiritual_matrix[i + 1][j].first != -1)
                spiritual_matrix[i][j].first = spiritual_matrix[i - 1][j - 1].first;

            if (spiritual_matrix[i + 1][j - 1].first != -1)
                spiritual_matrix[i][j].first = spiritual_matrix[i - 1][j - 1].first;

            if (spiritual_matrix[i][j - 1].first != -1)
                spiritual_matrix[i][j].first = spiritual_matrix[i - 1][j - 1].first;
        }
    }

    for (int i = 0; i < spiritual_matrix.size(); i++)
    {
        for (int j = 0; j < spiritual_matrix[i].size(); j++)
        {
            cout << spiritual_matrix[i][j].first << " ";
        }
        cout << endl;
    }

    return 0;
}

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
        int n, m;
        cin >> n >> m;

        vector<vector<char>> a(n, vector<char>(m));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> a[i][j];
            }
        }

        cout << maxCities(a, n, m) << "\n";
    }

    return 0;
}
// // Current Sample IO
// 2
// 5 5
// ....*
// .....
// ..*..
// .....
// .....
// 1 2
// **

// -1 -1 -1 -1 -1
// -1 1 -1 -1 -1
// -1 -1 1 -1 -1
// -1 -1 -1 1 -1
// -1 -1 -1 -1 -1
// 0
// -1 -1
// 0
