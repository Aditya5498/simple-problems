:-)

BINARY TREE MAX PATH SUM LEET CODE 124

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

Example :- 
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

SOLUTION :- O(N)

This can be solved by using DFS. We can calculate the maximum path for each child node until we reach the leaf node. After this, Add the value which has max sum of the child node.

Explanation can be found here -> https://www.youtube.com/watch?v=Hr5cWUld4vU

1. Keep a Global variable and update it's value for each node you traverse. This global variable can be considered as max sum path value found until now. To do this, each node is considered as a max path found till now.

2. When traversing upward, update the global variable without considering negative values.