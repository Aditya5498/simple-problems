#include<iostream>
#include<vector>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size()+s2.size()) {
            return false;
        }
        
        vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1, false));
        
		// init
        dp[s1.size()][s2.size()] = true;
        
		// dp logic
        for (int i=s1.size(); i>=0; i--) {
            for (int j=s2.size(); j>=0; j--) {
                if(i<s1.size() && s1[i]==s3[i+j] && dp[i+1][j]) {
                    dp[i][j] = true;
                }
                if(j<s2.size() && s2[j]==s3[i+j] && dp[i][j+1]) {
                    dp[i][j] = true;
                }
            }
        }
        
        return dp[0][0];
    }

int main(){
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    cout<<isInterleave(s1,s2,s3);
}