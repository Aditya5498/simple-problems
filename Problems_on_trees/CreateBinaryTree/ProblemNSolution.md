Given Inorder Traversal of a Special Binary Tree in which the key of every node is greater than keys in left and right children, construct the Binary Tree and return root.

Examples: 

Input: inorder[] = {5, 10, 40, 30, 28}
Output: root of following tree
         40
       /   \
      10     30
     /         \
    5          28 

Input: inorder[] = {1, 5, 10, 40, 30, 
                    15, 28, 20}
Output: root of following tree
          40
        /   \
       10     30
      /         \
     5          28
    /          /  \
   1         15    20


Solution :- O(n^2), O(n)

Find the max element in each iteration,
use recursive loop to find max element in the left of the max index
and use recursive loop to find the max element from right half of the first iteration.
return the root.