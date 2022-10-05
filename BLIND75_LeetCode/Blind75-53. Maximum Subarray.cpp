//https://leetcode.com/problems/maximum-subarray/description/
// Uses Kadane's algorithm

 int maxSubArray(vector<int>& nums) {
        int currSum = -999999, maxSum=nums[0];

        for(int i=0;i<nums.size();i++){
            currSum = max(nums[i],currSum+nums[i]);
            maxSum=max(maxSum,currSum);
        }
    return maxSum;

    }