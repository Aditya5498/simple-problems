// https://leetcode.com/problems/contains-duplicate/

 bool containsDuplicate(vector<int>& nums) {
        int arr[100000] = {0};
           map<int,int> hm;

           for(int i=0;i<nums.size();i++){
               if(hm.find(nums[i])!=hm.end()) return true;
               else hm[nums[i]] = 1;
           }
        return false;
    }