// Approach
// We can look at this using a Bottom-Up Dynamic Programming (DP) approach.
// We'll be iterating character by character over the input string in reverse, keeping track of how many different ways we can decode the string so far in an array called dp.
// When doing this, there are a couple of cases that we need to consider:

// Number at index is equal to 0
// - Since 0 isn't a valid number to start with, we set dp[i] = 0 if s[i] == 0.
// - If this isn't the case, then we know the number at s[i] is valid, and we set dp[i] = dp[i+1].
// Check whether we can create a valid 2 digit number
// - Since the range of valid numbers to decode is 1-26 we need to check whether our current number can be combined into a valid 2 digit number.
// - Our two sets of valid 2 digit numbers are 10-19 and 20-26 and we can check this by looking at whether s[i] == 1, or whether s[i] == 2 && 0 <= s[i+1] <= 6
// - If we have a valid two digit number, then we can add dp[i+1] to dp[i]
// These cases, especially the second, may not seem completely intuitive at first, but the explanation below should clear up any confusion.

// Explanation
// The first case is the simpler of the two, but may not make sense initally. We can think of this case as being If there is a valid number, then we maintain the previous number of different ways to decode the string.

// Tthe second case is where it gets more complicated. We can think of this case as being If we can form a valid 2 digit number, then the number ways to decode the string will increase by the number of ways to decode the substring that begins after the second digit of our 2 digit number. To give an example:


public class Solution {
    public int NumDecodings(string s) {
var dp = new int[s.Length+1];
        dp[s.Length] = 1;

        for (int i = s.Length-1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                dp[i] = 0;
            }
            else
            {
                dp[i] = dp[i + 1];
            }

            if (i + 1 < s.Length && (s[i] == '1' || (s[i] == '2' && (int)Char.GetNumericValue(s[i+1]) >= 0 && (int)Char.GetNumericValue(s[i+1]) <= 6)))
            {
                dp[i] += dp[i+2];
            }
        }

        return dp[0];
    
    }
}