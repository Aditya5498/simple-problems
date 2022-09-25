Given a Binary Tree, find the vertical sum of the nodes that are in the same vertical line. Print all sums through different vertical lines.
Examples: 
 

      1
    /   \
  2      3
 / \    / \
4   5  6   7
The tree has 5 vertical lines

Vertical-Line-1 has only one node 4 => vertical sum is 4 
Vertical-Line-2: has only one node 2=> vertical sum is 2 
Vertical-Line-3: has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12 
Vertical-Line-4: has only one node 3 => vertical sum is 3 
Vertical-Line-5: has only one node 7 => vertical sum is 7
So expected output is 4, 2, 12, 3 and 7 

Solution :- 
This can be solved using DFS- inorder traversal.
Take a horizontal distance variable as 0.
For every left traversal, decrease the horizontal distance by 1 and
Add the newly found variable in a hash map.
For every right traversal, increase the horizontal distance by 1.

After the DFS is complete, print out all the variables in hashmap.
