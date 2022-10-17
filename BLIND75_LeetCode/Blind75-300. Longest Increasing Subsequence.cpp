https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size,1);

        for(int i=0;i<size;i++){
            for(int j=size-1;j>=size-i-1;j--){
                if(nums[size-i-1] < nums[j]) dp[size-i-1] = max(dp[size-i-1], dp[j]+1);
            }
        }

        int maxNum = INT_MIN;
        for(int i=0;i<size;i++) {
            cout<<dp[i]<<" ";
            maxNum = max(maxNum,dp[i]);
        }
        return maxNum;

    }
};