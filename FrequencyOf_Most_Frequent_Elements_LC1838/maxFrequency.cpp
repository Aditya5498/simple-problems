#include<iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;

int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long l=0, r=0, out=0;
        long total=0;
        while(r<nums.size()){
            
            total += nums[r];
            
            while(nums[r] * (r-l+1) > total + k)
            {
                total-=nums[l];
                l++;
            }
            
            out = max(out,(r-l+1));
            r++;
        }
        return out;
    }

int main(){
    vector<int> nums = {1,2,4};
    cout<<maxFrequency(nums,5);
    return 0;
}