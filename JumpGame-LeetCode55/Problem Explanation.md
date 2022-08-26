Problem :- (Leet Code 55 -> https://leetcode.com/problems/jump-game/)
You are given an integer array nums. 
You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 😀😅🤔🚲🚗🚆🚝☄🍣🍜(*/ω＼*)

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. 
Its maximum jump length is 0, which makes it impossible to reach the last index.

Explanation :-

Video -> https://www.youtube.com/watch?v=Yan0cv2cLy8

I'll be solving by bottom up approach. 😉🤔

Assume that you'll reach the end, so the starting point is in the end(set this as the goal).
And in reverse order check if you'll reach the goal by verifying whether goal <= Index + value at this index. If yes, the update the goal to the present index 