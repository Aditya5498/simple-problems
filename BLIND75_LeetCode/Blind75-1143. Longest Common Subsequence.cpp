https://leetcode.com/problems/longest-common-subsequence/description/

class Solution {
public:


    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> arr(text1.size()+1,vector<int>(text2.size()+1,0));

        for(int i=text1.size()-1;i>=0;i--){
            for(int j=text2.size()-1;j>=0;j--){
                if(text1[i] == text2[j]) arr[i][j] += arr[i+1][j+1]+1;
                else arr[i][j] = max(arr[i+1][j], arr[i][j+1]);
            }
        }

        return arr[0][0];
    }
};