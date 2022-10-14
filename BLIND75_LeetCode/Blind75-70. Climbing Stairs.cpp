https://leetcode.com/problems/climbing-stairs/description/


class Solution {
public:
    int climbStairs(int n) {
        int first = 1,second = 1,temp=first;
        for(int i=0;i<n-1;i++){
            temp = first;
            first = first + second;
            second = temp;
        }
        return first;
    }
};