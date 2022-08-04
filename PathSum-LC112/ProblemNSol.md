Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.

Tree Image attached in this folder.

Sol :- O(n)

This can easily be solved using recursion

Use in order traversal.
while passing through every node, check if it's a leaf node ->if yes, then check the sum == target.
else go tot the next node.

Explanation can be found here -> https://www.youtube.com/watch?v=LSKQyOz_P8I

:-)😊😂👌🤔©