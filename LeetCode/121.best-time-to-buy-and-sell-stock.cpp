/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
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
// @lc code=end

