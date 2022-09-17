/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> ump;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(!ump[target-nums[i]].empty()) 
                return {i, ump[target-nums[i]][0]};
            ump[nums[i]].push_back(i);
        }
        
        
        return {-1,-1};
    }
};
// @lc code=end

