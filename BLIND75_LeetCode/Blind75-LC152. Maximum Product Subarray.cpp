// https://leetcode.com/problems/maximum-product-subarray/description/
// So the approach of this code is 
//somewhere similar to Kadan's Algo (max sum subarray) ,
//But in this Ques we will iterate from both side
// starting and ending and keep 2 product variables to store the products 
//rom both side , and during each iteration we will keep checking for the max product . But there is twist as if any num is 0 then it will make the whole product as 0 so to avoid this first of all we have to check if 0 can be max product or not and after checking we will assign the product as 1 and continue to next iteration. :)

 int n = nums.size();
        int ans = INT_MIN;
        int prod1=1 , prod2 =1;
        
        for(int i=0,j=n-1;i<n && j>=0;i++,j--){
            prod1 *= nums[i];
            prod2 *= nums[j];
            
            if(prod1==0 || prod2==0){
                ans = max(ans,max(prod1,prod2));
                if(prod1==0)
                    prod1=1;
                else
                    prod2=1;
                continue;
            }
            ans = max(ans,max(prod1,prod2));
        }
        return ans;