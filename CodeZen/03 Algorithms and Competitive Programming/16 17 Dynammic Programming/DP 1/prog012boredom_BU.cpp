#include <iostream>
#include <vector>
using namespace std;
// #include "solution.h"
int n;
vector<int> A;

int solve(int n, vector<int> A)
{
    vector<int> frequency(1001, 0);
    vector<int> dp(1001, 0);

    for (auto &ele : A)
        frequency[ele]++;

    dp[0] = 0;
    dp[1] = 1 * frequency[1];

    for (int i = 2; i <= 1000; i++)
    {
        auto option1 = dp[i - 1];
        auto option2 = dp[i - 2] + (i * frequency[i]);
        dp[i] = max(option1, option2);
    }

    // for(auto ele :dp)
    //     cout << ele << " ";
    // cout << endl;

    return dp[1000];
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    cout << solve(n, A) << endl;
}

// Sample Input :
// 2
// 1 2
// Sample Output :
// 2