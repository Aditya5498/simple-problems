Problem:- 
Write an efficient program to find the sum of the contiguous subarray within a one-dimensional array of numbers that has the largest sum. 


Solution :-
Explanation: O(n)
The simple idea of Kadane’s algorithm is to look for all positive contiguous segments of the array (max_ending_here is used for this). And keep track of the maximum sum contiguous segment among all positive segments (max_so_far is used for this). Each time we get a positive-sum compare it with max_so_far and update max_so_far if it is greater than max_so_far 