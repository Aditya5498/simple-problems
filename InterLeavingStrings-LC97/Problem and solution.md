Leet Code 97 -> https://leetcode.com/problems/interleaving-string/

Problem :- 
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

Example :- 
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.

Solution :- the best approach is using Dynamic programming O(m*n) 
Understand the solution from here -> https://youtu.be/3Rw3p9LrgvE

Recursion:
Logic: When we start index of both strings s1 and s1 from 0, we can compute index of s3 as sum of both indices. We just check if any index is in bounds or not. If it is in bounds we compare the char at that index with s3's index and recursively call function by incrementing compared index if char matches.

Dynamic Programming logic:-
step 1: convert base case into initialization
step 2: convert recursion logic into loops in reverse order