#include <iostream>
#include <vector>
using namespace std;
// #include "solution.h"
int n;
vector<int> A;

int solve(int n, vector<int> A)
{
    vector<int> frequency(n, 0);
    vector<int> dp(n + 1, 0);

    for (auto &ele : A)
        frequency[ele]++;

    dp[0] = A[0];
    dp[1] = A[1];
    for (int i = 2; i <= A.size(); i++)
    {
        auto option1 = dp[i - 1];
        auto option2 = dp[i - 2] + i * frequency[i];
        dp[i] = max(option1, option2);
    }

    return dp[n];
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