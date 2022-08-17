#include<iostream>
#include<vector>
using namespace std;

// this is recursive solution
   bool check1(string s, string s1, string s2, int i1, int i2) {
        if(i1==s1.size() && i2==s2.size()) {
            return true;
        }

        if(i1<s1.size() && s[i1+i2] == s1[i1]) {
            if (check(s, s1, s2, i1+1, i2)) {
                return true;
            }
        }
        if(i2<s2.size() && s[i1+i2]==s2[i2]) {
            if (check(s, s1, s2, i1, i2+1)) {
                return true;
            }
        }
        return false;
    }
    bool isInterleave1(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size()) {
            return false;
        }
        return check1(s3, s1, s2, 0, 0);
    }

    // recursive solution with memoization
 vector<vector<int>> dp;
    bool check(string s, string s1, string s2, int i1, int i2) {
		// base case
        if(i1==s1.size() && i2==s2.size()) {
            return true;
        }
        
		// memorization
        if(dp[i1][i2] != -1) {
            return dp[i1][i2];
        }
        
		// recursion
        if(i1<s1.size() && s[i1+i2] == s1[i1]) {
            if (check(s, s1, s2, i1+1, i2)) {
                dp[i1][i2] = 1;
                return true;
            }
        }
        if(i2<s2.size() && s[i1+i2]==s2[i2]) {
            if (check(s, s1, s2, i1, i2+1)) {
                dp[i1][i2] = true;
                return true;
            }
        }
        dp[i1][i2] = false;
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size()) {
            return false;
        }
        dp.resize(s1.size()+1, vector<int>(s2.size()+1, -1));
        return check(s3, s1, s2, 0, 0);
    }

int main(){
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    cout<<isInterleave(s1,s2,s3);
}