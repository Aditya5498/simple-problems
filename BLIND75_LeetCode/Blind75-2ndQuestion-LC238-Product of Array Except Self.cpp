//https://leetcode.com/problems/product-of-array-except-self/description/
// approach -> use a prefix array and a postfix array
// in the prefix array calculate the multiplied values until now and 
// in the posfix array calculate the values from reverse
// in the last multily both the array's to get the result
vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1;
        vector<int> result;

        for(int i=0;i<nums.size();i++){
            result.push_back(prefix);
            prefix *= nums[i];
        }

            int postfix = 1;
        for(int j=nums.size()-1;j>=0;j--){
                result[j]*=postfix;
                postfix*=nums[j];
        }

        return result;
    }