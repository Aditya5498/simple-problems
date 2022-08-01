Problem : To find the median in a data stream.

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

Solution :

1) Brute Force way :- O(N) 

Take an array and add the elements into the array in order/ sorted manner.
For ex - If the inputs are 3,1,2,9,10. Then final array after inserting elements would be {1,2,3,9,10}

2) Using Heap Data Structure :- O(logN)
We will use heap data structure.
Since for even number of elements, the median is average of mid 2 elements, take 2 heap data structure.
One for keeping the smaller numbers and other for keeping the larger numbers. The smaller heap will be using Max Heap and the larger heap will be using Min Heap.
So at anytime, median = (1st heap's largest ele + 2nd Heap's least ele)/2.

For writing the algo, we need to keep things in mind :-
i) The difference of both heap data structure cannot be more than 1/
ii) The largest element of the 1st heap should be <= least element from the 2nd Heap.


LeetCode 295 -> Explanation can be found here : https://www.youtube.com/watch?v=itmhHWaHupI&t=914s

:-)
Code :- You can understand the solution from here -> https://leetcode.com/problems/find-median-from-data-stream/discuss/2349707/C%2B%2B-Simple-Heap-solution-Detailed-Explanation