https://leetcode.com/problems/missing-number/description/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n = nums.size();
        int sum = (n * ( 1 + n )) / 2; 
        
        int total = 0;
        bool f = false;
        for(int a: nums){
            if(a == 0) f = true;
            total += a;
        }
        
        if(f == false) return 0;
        return sum - total;
    }
};