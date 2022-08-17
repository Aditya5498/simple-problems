😀🙄🥱

Problem :- 
Find a triplet from three linked lists with sum equal to a given number

Given three linked lists, say a, b and c, find one node from each list such that the sum of the values of the nodes is equal to a given number. 
For example, if the three linked lists are 12->6->29, 23->5->8, and 90->20->59, and the given number is 101, the output should be triple “6 5 90”.
In the following solutions, size of all three linked lists is assumed same for simplicity of analysis. The following solutions work for linked lists of different sizes also.


Solution :- Time -> O(n^2) & ⚓🔱😒 Space -> O(n)

1) A simple method to solve this problem is to run three nested loops. The outermost loop picks an element from list a, the middle loop picks an element from b and the innermost loop picks from c. The innermost loop also checks whether the sum of values of current nodes of a, b and c is equal to given number. The time complexity of this method will be O(n^3).

2) Here I'll be explaning another solution to reduce the time complexity of above naive solution.
i) Construct an array and insert all the values of the 3 linked list. O(n)
ii) Sort the array. O(nlogn)
iii) Fix one element and use 2 pointer technique to find the sum. O(n^2)😏😫😑🤘🖖
You can find the detailed explanation of how to find triplet sum from a sorted array here -> https://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/#:~:text=The%20following%20code%20implements%20this,to%20end%20(loop%20counter%20k) 



