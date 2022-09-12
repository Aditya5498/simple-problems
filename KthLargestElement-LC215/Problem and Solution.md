from xml.dom.minidom import Element


Problem :- 
😀😆😅😚
Find the Kth Largest element in an array.
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

You must solve it in O(n) time complexity.

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

Solution :- O(n)
Use a min heap.
Add every Element of the array in the min heap and after adding 
the last element, pop out the last n-k Elements and then return the top.