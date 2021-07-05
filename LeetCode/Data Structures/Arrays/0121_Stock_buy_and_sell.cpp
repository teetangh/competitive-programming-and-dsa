#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minBuy = INT_MAX;
        int minIndex;
        int profit = INT_MIN;

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minBuy)
                minBuy = prices[i];
            profit = max(profit, prices[i] - minBuy);
        }
        return profit;
    }
};