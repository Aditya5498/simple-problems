https://leetcode.com/problems/house-robber/description/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() <3) return max(nums[0], nums[1]);
        vector<int> dp(nums.size());
        int maxNum = INT_MIN;
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0]+nums[2];
        maxNum = max(dp[0], max(dp[1],dp[2]));
        cout<<dp[0]<<" "<<dp[1]<<" "<<dp[2]<<" ";
        for(int i=3;i<nums.size(); i++){
            dp[i] = nums[i] + max(dp[i-2],dp[i-3]);
            maxNum = max(maxNum,dp[i]);
            cout<<dp[i]<<" ";
            }
        return maxNum;
    }
};